from backtracking_lib import GridBoard, Backtracking

# Define board
COLUMNS = 6
ROWS = 4
#green_towers = {(1, 2), (1, 5), (2, 1), (3, 6), (4, 2), (4, 5)}
#red_towers = {(1, 3), (2, 3), (3, 3)}

green_towers = [(1,6), (1,3)]
red_towers = [(2,3), (3,3)]

grid = GridBoard(ROWS, COLUMNS, green_towers, red_towers)

# Initialize the backtracking tool
backtracker = Backtracking(grid, initial_position=(1,1))
optimal_path = backtracker.findPath()
print(optimal_path)