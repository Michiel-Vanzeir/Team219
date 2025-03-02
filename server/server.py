# app.py
from flask import Flask, render_template
from flask_socketio import SocketIO, emit
from backtracking_lib import GridBoard, Backtracking

app = Flask(__name__)

# Allow connections from other origins (including your Live Server port)
socketio = SocketIO(app, cors_allowed_origins="*")

@app.route('/')
def index():
    return "Flask Socket.IO Server Running"

def convertTowerdataToSet(tower_data):
    stripped_data = tower_data.strip('{}')
    coordinate_pairs = stripped_data.split('),(')
    tower_set = set()

    for pair in coordinate_pairs:
        # Clean up the coordinates by removing unnecessary characters
        pair = pair.strip('()')
        x, y = pair.split(',')
        tower_set.add((int(x), int(y)))

    return tower_set



@socketio.on('grid_parameters')
def DetermineShortestPath(data):
    try:
        cols = int(data['cols'])
        rows = int(data['rows'])
        green_towers = convertTowerdataToSet(data['green_towers'])
        red_towers = convertTowerdataToSet(data['red_towers'])
    except KeyError:
        emit('error', {'message': 'Missing parameters in data dictionary'})
        print("Error: Missing parameters in data dictionary")
        return

    
    grid = GridBoard(rows, cols, green_towers, red_towers)
    backtracker = Backtracking(grid, initial_position=(1,1))
    optimal_path = backtracker.findShortestPath()

    print(f"optimal path: {optimal_path}")
    path_data = {
        'path': optimal_path
    }

    emit('navigation_data', path_data)
    print(f"Received from client: {data}")
    print(f"Sent to client: {path_data}")

if __name__ == '__main__':
    socketio.run(app, host='localhost', port=5000, debug=True)
