from itertools import permutations

class GridBoard:
    def __init__(self, rows: int, cols: int, green_towers: set, red_towers: set):
        self.rows = rows
        self.columns = cols
        self.green_towers = green_towers
        self.red_towers = red_towers

        self.positions = self.createAllPositions()
        self.addValidNeighbours()

    def addTower(self, position: tuple, type: str):
        if type.lower() == "red":
            self.red_towers.add(position)
        elif type.lower() == "green":
            self.green_towers.add(position)
        else:
            raise ValueError("Please enter a valid type ('green' or 'red')")

    def getTowers(self, type: str):
        if type.lower() == "red":
            return self.red_towers
        elif type.lower() == "green":
            return self.green_towers
        elif type.lower() == "all":
            return self.green_towers | self.red_towers
        else:
            raise ValueError("Please enter a valid type ('green', 'red', 'all')")

    def createAllPositions(self):
        positions = {}
        for row in range(1, self.rows+1):
            for col in range(1, self.columns+1):
                positions[(row, col)] = None

        return positions

    def addValidNeighbours(self):
        for position in self.positions.keys():

            neighbours = [
                (position[0] + 1, position[1]),
                (position[0] - 1, position[1]),
                (position[0], position[1] + 1),
                (position[0], position[1] - 1) 
            ]

            self.positions[position] = [neighbour for neighbour in neighbours if neighbour in self.positions and neighbour not in self.red_towers]
    
    def getPositions(self):
        return self.positions
    
class Backtracking:
    def __init__(self, gridboard: GridBoard, initial_position: tuple):
        self.gridboard = gridboard
        self.initial_position = initial_position
        self.visited = set()
        self.counter = 0
        
        self.optimal_path = []
        self.optimal_subpath = []

    def findShortestPath(self):
        all_tower_orders = self.calculateTowerPermutations()
        all_found_paths = []

        for tower_order in all_tower_orders:
            
            starting_position = self.initial_position
            fullpath = []
            for tower in tower_order:
                found_subpath = self.findSubPath(starting_position, tower)
                fullpath.extend(found_subpath[:-1])

                starting_position = tower

            # Find the way back to the garage
            found_subpath = self.findSubPath(starting_position, self.initial_position)
            fullpath += found_subpath

            all_found_paths.append(fullpath)

        # Find the shortest path
        shortest_path = min(all_found_paths, key=len)
        return shortest_path

    def findSubPath(self, starting_position, finish_position):
        self.visited.clear()
        self.optimal_subpath = []
        self._recursiveBacktracking(starting_position, path=[], goal_position=finish_position)
        return self.optimal_subpath

    def _recursiveBacktracking(self, current_position, path, goal_position):
        path.append(current_position)
        self.visited.add(current_position)

        # Pruning
        if self.optimal_path and len(path) >= len(self.optimal_path):
            path.pop()
            self.visited.add(current_position)
            return

        # Check if path is completed
        if self.checkPath(path, goal_position):
            if len(path) < len(self.optimal_subpath) or len(self.optimal_subpath) == 0:
                self.optimal_subpath = path.copy()


        neighbours = self.gridboard.positions[current_position]
        for neighbour in neighbours:
            if  neighbour not in self.visited or len(neighbours) == 1: 
                self.counter += 1
                #print("Now:", self.counter)  # Commented out to improve performance
                self._recursiveBacktracking(neighbour, path, goal_position) 

        # Backtracking / explore another neighbour
        path.pop()
        self.visited.discard(current_position)

    def checkPath(self, path, goal_position):
        # Check if the car is back to the garage
        if path[-1] != goal_position:
            return False
        return True
    
    def calculateTowerPermutations(self):
        return list(permutations(self.gridboard.green_towers))
    