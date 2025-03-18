import wifi
import socketpool
import time
from adafruit_httpserver import Websocket

SSID = "PICO-TEAM-219"  # Change this
PASSWORD = "team219"  # Change this for security

wifi.radio.connect(SSID, PASSWORD)
print("Connected to WiFi. IP Address:", wifi.radio.ipv4_address)

pool = socketpool.SocketPool(wifi.radio)
websocket = None

def connect_to_websocket():
    global websocket
    try:
        websocket = Websocket(pool)
        websocket.connect("ws://192.168.1.X:8765")  # Replace X with your PC's IP
        print("Connected to WebSocket!")
    except Exception as e:
        print("WebSocket Connection Failed:", e)

connect_to_websocket()

while True:
    if websocket:
        try:
            data = websocket.receive(fail_silently=True)
            if data:
                motor_values = [int(x) for x in data.split(",")]
                print("Received motor values:", motor_values)
                # Send these values to motor control logic here
        except Exception as e:
            print("WebSocket Error:", e)
            websocket = None
            time.sleep(1)
            connect_to_websocket()
    
    time.sleep(0.1)  # Prevents high CPU usage
