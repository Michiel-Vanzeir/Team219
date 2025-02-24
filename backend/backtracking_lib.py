from collections import defaultdict

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
        self.path = list()
        self.visited = defaultdict(int)
        self.counter = 0
        
        self.optimal_path = []
        self.max_visits = 2

    def findPath(self):
        self.visited.clear()
        self.optimal_path = []
        self._recursiveBacktracking(self.initial_position, [])
        return self.optimal_path

    def _recursiveBacktracking(self, current_position, path):
        path.append(current_position)
        self.visited[current_position] += 1

        # Pruning
        if self.optimal_path and len(path) >= len(self.optimal_path):
            path.pop()
            self.visited[current_position] -= 1
            return

        # Check if path is completed
        if self.checkPath(path):
            if len(path) < len(self.optimal_path) or len(self.optimal_path) == 0:
                self.optimal_path = path.copy()


        neighbours = self.gridboard.positions[current_position]
        for neighbour in neighbours:
            if  self.visited[neighbour] < self.max_visits or len(neighbours) == 1 or (neighbour == self.initial_position and self.visitedAllTowers(path)): 
                self.counter += 1
                #print("Now:", self.counter)  # Commented out to improve performance
                if self.counter > 15000000:
                    print("stop")
                self._recursiveBacktracking(neighbour, path) 

        # Backtracking / explore another neighbour
        path.pop()
        self.visited[current_position] -= 1

    def checkPath(self, path):
        # Check if the car is back to the garage
        if path[-1] != self.initial_position:
            return False

        # Check if the path length is sufficient to include all green towers
        if len(path) < len(self.gridboard.green_towers): 
            return False
        
        # Check if all green towers are in the path
        for tower in self.gridboard.green_towers: 
            if tower not in path:
                return False
            
        return True
    
    def visitedAllTowers(self, path):
        for tower in self.gridboard.green_towers:
            if tower not in path:
                return False
        return True
        
