import pygame
import math
import time
import asyncio
import websockets

# Initialize Pygame and Joystick
def init():
    pygame.init()
    pygame.joystick.init()

    if pygame.joystick.get_count() == 0:
        print("No joystick detected!")
        return None
    else:
        joystick = pygame.joystick.Joystick(0)
        joystick.init()
        print(f"Controller: {joystick.get_name()}")
        return joystick

# Convert Cartesian to Polar coordinates
def cartesian_to_polar(x, y):
    r = math.sqrt(x**2 + y**2)
    theta = math.atan2(y, x)
    return r, theta

# Compute motor values based on joystick input
def get_motor_values(joystick):
    pygame.event.pump()
    axes = [joystick.get_axis(i) for i in range(joystick.get_numaxes())][0:3] 
    left_x = axes[0]
    left_y = -axes[1]  # Invert Y for correct forward/backward movement
    turn = axes[2]  # Right joystick X-axis for rotation

    # Convert to polar
    power, theta = cartesian_to_polar(left_x, left_y)
    sin = math.sin(theta - math.pi / 4)
    cos = math.cos(theta - math.pi / 4)
    max_val = max(abs(sin), abs(cos))

    # Motor calculations
    left_front = (power * cos / max_val) + turn
    right_front = (power * sin / max_val) - turn
    left_rear = (power * sin / max_val) + turn
    right_rear = (power * cos / max_val) - turn

    # Rescale if needed
    scale = max(1, power + abs(turn))
    left_front /= scale
    right_front /= scale
    left_rear /= scale
    right_rear /= scale

    # Remap from [-1, 1] to [-255, 255]
    left_front = int(left_front * 255)
    right_front = int(right_front * 255)
    left_rear = int(left_rear * 255)
    right_rear = int(right_rear * 255)

    return f"{left_front},{right_front},{left_rear},{right_rear}"

# WebSocket server to send motor values
async def send_motor_data(websocket, path):
    joystick = init()
    if not joystick:
        return

    while True:
        motor_values = get_motor_values(joystick)
        await websocket.send(motor_values)
        print(f"Sent: {motor_values}")
        await asyncio.sleep(0.1)  # Send updates every 100ms

# Start the WebSocket server
async def start_server():
    server = await websockets.serve(send_motor_data, "0.0.0.0", 8765)  # Replace with your PC's IP if needed
    print("WebSocket Server Started on ws://0.0.0.0:8765")
    await server.wait_closed()

# Run the WebSocket server
asyncio.run(start_server())
