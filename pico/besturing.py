# Write your code here :-)
import board
import pwmio
import math
import time
import digitalio
from analogio import AnalogIn

#### --------- CLASSES --------- ####

class Motor:
    def __init__(self, pwm_pin, dir_pin):
        self.pwm = pwmio.PWMOut(pwm_pin, frequency=1000, duty_cycle=0)
        self.direction = digitalio.DigitalInOut(dir_pin)
        self.direction.direction = digitalio.Direction.OUTPUT

    def set_speed(self, speed: int):
        """Sets the speed of the motor (0-255)."""
        if speed >= 0:
            self.direction.value = True  # Forward direction
        else:
            self.direction.value = False  # Reverse direction
        self.pwm.duty_cycle = int(abs(speed) / 255 * 65535)


class MotorController:
    def __init__(self, motor_pins):
        self.motors = [Motor(pwm_pin, dir_pin) for pwm_pin, dir_pin in motor_pins]

    def setMotorSpeeds(self, speeds: list):
        """
        Sets the speed for each motor.
        speeds is a list of 4 integers for the 4 motors in the format:
        [motor1_speed, motor2_speed, motor3_speed, motor4_speed]
        """
        for motor, speed in zip(self.motors, speeds):
            motor.set_speed(speed)

    def stop_all_motors(self):
        """Stops all motors by setting their speed to 0."""
        for motor in self.motors:
            motor.set_speed(0)
    
    def turnRight(self, speed=200, duration=2.5):
        """
        Turns the robot to the right by running the motors accordingly.
        Speed is between 0-255.
        Duration determines how long the turn lasts.
        """
        self.set_motor_speeds([speed, -speed, speed, -speed])  # Rotate clockwise
        time.sleep(duration)
        self.stop_all_motors()


class MainController:
    def __init__(self, max_ldr_reading: float, min_ldr_reading: float):
        # Parameter attributes
        self.max_ldr_reading = max_ldr_reading
        self.min_ldr_reading = min_ldr_reading
        self.threshold = (self.max_ldr_reading + self.min_ldr_reading) / 2


        # Other default attributes
        self.near_intersection = False
        self.front_ldrs_indices = [0, 1, 7]
        self.ldr_distances_x = (0.0, 2.47, 3.5, 2.47, 0.0, -2.47, -3.5, -2.47)
        self.ldr_distances_y = (3.5, 2.47, 0.0, -2.47, -3.5, -2.47, 0.0, 2.47)

    def calculateLineDeviation(self, ldr_readings, max_ldr_reading, min_ldr_reading):
        line_deviation = 0.0
        total_activation = 0.0
        activation_range = max_ldr_reading - min_ldr_reading

        # Calculate the activations and weighted sum
        for reading, distance in zip(ldr_readings, self.ldr_distances_x):
            activation = 1 - (reading - min_ldr_reading) / activation_range
            line_deviation += activation * distance
            total_activation += activation

        if total_activation != 0:
            line_deviation /= total_activation

            return line_deviation
        else:
            return 0.0
            
    def compute_weighted_position(self, activations, neighboring_indices):
        weighted_x = 0.0
        weighted_y = 0.0
        total_activation = 0.0

        for index in neighboring_indices:
            weighted_x += activations[index] * self.ldr_distances_x[index]
            weighted_y += activations[index] * self.ldr_distances_y[index]
            total_activation += activations[index]

        if total_activation != 0:
            weighted_x /= total_activation
            weighted_y /= total_activation

        return weighted_x, weighted_y


    def calculateLineAngle(self, ldr_readings):
        activations = []
        activation_range = self.max_ldr_reading - self.min_ldr_reading

        # Variables to track the indices of the two highest activations
        highest_activation_idx = -1
        second_highest_activation_idx = -1
        highest_activation = 0.0
        second_highest_activation = 0.0

        # Calculate activations for each LDR
        for index, reading in enumerate(ldr_readings):
            activation = 1 - (reading - self.min_ldr_reading) / activation_range
            activations.append(activation)

            # Update highest and second highest activations
            if activation > highest_activation:
                second_highest_activation = highest_activation
                second_highest_activation_idx = highest_activation_idx
                highest_activation = activation
                highest_activation_idx = index
            elif activation > second_highest_activation:
                second_highest_activation = activation
                second_highest_activation_idx = index

        # Make sure the highest index is in the front of the robot
        if highest_activation_idx not in {7, 0, 1}:
            temp_idx = highest_activation_idx
            highest_activation_idx = second_highest_activation_idx
            second_highest_activation_idx = temp_idx

        # Select neighboring LDRs of the two most activated ones
        highest_neighbors = [(highest_activation_idx - 1) % 8, highest_activation_idx, (highest_activation_idx + 1) % 8]
        second_highest_neighbors = [(second_highest_activation_idx - 1) % 8, second_highest_activation_idx, (second_highest_activation_idx + 1) % 8]

        # Calculate the weighted line intersects
        weighted_x1, weighted_y1 = self.compute_weighted_position(activations, highest_neighbors)
        weighted_x2, weighted_y2 = self.compute_weighted_position(activations, second_highest_neighbors)

        # Calculate the line angle
        delta_x = weighted_x2 - weighted_x1
        delta_y = abs(weighted_y2 - weighted_y1)
        angle = math.degrees(math.atan2(delta_y, delta_x)) - 90

        
        return angle if abs(angle) < 70.0 else 0.0
            
    def onIntersection(self, ldr_readings):
        return  all(ldr_readings[index] < self.threshold for index in self.front_ldrs_indices)
        

    def nearIntersection(self, ldr_readings):
        return sum([reading < self.threshold for reading in ldr_readings]) <= 3
    
    def mainControlLogic(self, ldr_readings):
        if self.onIntersection(ldr_readings):
            return {"TURN": None}
        else:
            line_deviation = self.calculateLineDeviation(ldr_readings)
            line_angle = self.calculateLineAngle(ldr_readings)
            return {"PID": [line_deviation, line_angle]}



    def calculateMotorSpeeds(self, line_deviation, angle_correction, base_speed=150):
        """
        Computes motor speeds for a mecanum drive while keeping values within [-255, 255].
        - line_deviation affects strafing.
        - angle_correction affects rotation.
        - base_speed is dynamically adjusted to prioritize speed.
        """
        strafe = line_deviation  # Strafing correction
        rotate = angle_correction  # Rotation correction

        # Compute raw motor speeds
        front_left = base_speed + strafe + rotate
        front_right = base_speed - strafe - rotate
        rear_left = base_speed - strafe + rotate
        rear_right = base_speed + strafe - rotate

        # Find max absolute speed
        max_speed = max(abs(front_left), abs(front_right), abs(rear_left), abs(rear_right), 255)

        # Normalize if any speed exceeds 255 to maintain efficiency
        scale = 255 / max_speed if max_speed > 255 else 1.0
        front_left = int(front_left * scale)
        front_right = int(front_right * scale)
        rear_left = int(rear_left * scale)
        rear_right = int(rear_right * scale)

        return [front_left, front_right, rear_left, rear_right]


class PIDController:
    def __init__(self, Kp=0, Kd=0, Ki=0):
        self.Kp = Kp
        self.Kd = Kd
        self.Ki = Ki

        # For derivative gain
        self.previous_error = 0

        # For integral gain
        self.cumulative_error = 0

    def calculate(self, error):
        derivative_gain = error - self.previous_error

        # Update controller state
        self.previous_error = error
        self.cumulative_error += error

        return self.Kp * error + self.Kd * derivative_gain + self.Ki * self.cumulative_error


class LDR:
    def __init__(self, pin):
        """Initialize the LDR sensor on the given pin."""
        self.ldr = AnalogIn(pin)

    def read_voltage(self):
        """Read and return the LDR sensor voltage (0V-3.3V)."""
        return (self.ldr.value * 3.3) / 65535


class LDRController:
    def __init__(self, ldr_pins):
        """Initialize the LDRController with a list of LDR pins."""
        self.ldrs = [LDR(pin) for pin in ldr_pins]

    def readAllValues(self):
        """Read the values from all LDRs and return them as a list."""
        return [ldr.read_voltage() for ldr in self.ldrs]

    def calibrate(self, duration=5):
        """
        Calibrate the LDRs by reading values for a given duration and returning the
        highest and lowest values recorded during that time.

        Args:
            duration: Time in seconds to read the sensor values for calibration.
        
        Returns:
            (min_values, max_values) tuple where each is a list of minimum and
            maximum values recorded for each LDR.
        """
        min_value = float('inf')
        max_value = float('-inf') 
        start_time = time.time()

        while time.time() - start_time < duration:
            values = self.readAllValues()
            for value in values:
                if value < min_value:
                    min_value = value
                if value > max_value:
                    max_value = value
            
            time.sleep(0.1)  # Short delay to avoid overwhelming the sensor

        return min_value, max_value

#### ---------- SETUP -------------- ####

# NOG IN TE VULLEN
MOTOR_PINS = [
    (board.GP0, board.GP1),  # Motor 1 (PWM, DIR)
    (board.GP2, board.GP3),  # Motor 2 (PWM, DIR)
    (board.GP4, board.GP5),  # Motor 3 (PWM, DIR)
    (board.GP6, board.GP7),  # Motor 4 (PWM, DIR)
]

# NOG IN TE VULLEN (hoe werkt de multiplexer?) LIEFST index 0 van de lijst = voorste pin en dan clockwise rond gaan
LDR_PINS = [ 
    board.A0,  # LDR 1
    board.A1,  # LDR 2
    board.A2,  # LDR 3
    board.A3,  # LDR 4
    board.A4,  # LDR 5
    board.A5,  # LDR 6
    board.A6,  # LDR 7
    board.A7,  # LDR 8
]

motor_controller = MotorController(MOTOR_PINS)
ldr_controller = LDRController(LDR_PINS)
min_ldr_value, max_ldr_value = ldr_controller.calibrate(duration=5)

print(f"Laagste LDR meting: {min_ldr_value}")
print(f"Hoogste LDR meting: {max_ldr_value}")

main_controller = MainController(max_ldr_reading=max_ldr_value, min_ldr_reading=min_ldr_value)

line_pid = PIDController(Kp=0.15, Kd=0.05, Ki=0.0)
angle_pid = PIDController(Kp=0.45, Kd=0.05, Ki=0.0)

#### ------------ LOOP ------------ ####

while True:
    ldr_readings = ldr_controller.readAllValues()

    action = main_controller.mainControlLogic(ldr_readings)

    if "TURN" in action:
        # Turn right using the motor controller
        motor_controller.turnRight(speed=200, duration=1.5)
    else:
        line_correction = line_pid.calculate(action["PID"][0])
        angle_correction = angle_pid.calculate(action["PID"][1])

        motor_speeds = main_controller.calculateMotorSpeeds(line_correction, angle_correction)

        motor_controller.setMotorSpeeds(motor_speeds)

    time.sleep(0.01)

        