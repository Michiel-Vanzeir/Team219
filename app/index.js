// Connect to the python server
const socket = io('http://localhost:5000');

// Declare the event listeners
document.addEventListener("DOMContentLoaded", () => {
    document.querySelector('.navigation-btn').addEventListener('click', flipPathCard);
    document.querySelector('.path-btn').addEventListener('click', () => {
        sendGridData();
        flipPathCard();
        createGrid();
    });
});

socket.on('connect', () => {
    console.log("Connected to Python server");
});

// Sends grid size to python
function sendGridData() {
    const rows = parseInt(document.getElementById('rows').value);
    const cols = parseInt(document.getElementById('columns').value);
    const green_towers = document.getElementById('green_towers').value;
    const red_towers = document.getElementById('red_towers').value;
    socket.emit('grid_parameters', { rows, cols, green_towers, red_towers });
    console.log(`Sent grid parameters: Rows: ${rows}, Cols: ${cols}`);
}

// Listens for shortest path from python
socket.on('navigation_data', (data) => {
    showShortestPath(data['path']);
    console.log("Received from Python:", data);
});

// Flips the path card
function flipPathCard() {
    document.querySelector('.path-card-inner')?.classList.toggle('flipped');
}

function createGrid() {
    const grid = document.getElementById('grid');
    const rows = parseInt(document.getElementById('rows').value) + 1;
    const cols = parseInt(document.getElementById('columns').value) + 1;

    grid.innerHTML = ''; // Clear the previous grid

    grid.style.gridTemplateRows = `repeat(${rows}, auto)`;
    grid.style.gridTemplateColumns = `repeat(${cols}, auto)`;

    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            const cell = document.createElement('div');
            cell.classList.add('grid-cell');
            grid.appendChild(cell);
        }
    }
}

function substractCoordinates (vertex1, vertex2) {
    return [vertex2[0] - vertex1[0], vertex2[1] - vertex1[1]];
}

function delay(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function showShortestPath(path_data) {
    const gridcells = document.querySelectorAll('.grid-cell');
    const rows = parseInt(document.getElementById('rows').value) + 1;
    const cols = parseInt(document.getElementById('columns').value) + 1;
    console.log("cols ", cols);
    previous_vertex = path_data[0];


    for (let i = 1; i < path_data.length; i++) {
        const current_vertex = path_data[i];
        const [dx, dy] = substractCoordinates(previous_vertex, current_vertex);

        if (dx === 1) {
            const grid_cell_number = (current_vertex[0]-1) * cols + current_vertex[1] - 1;
            const adjacent_cell_number = grid_cell_number + 1;
            gridcells[grid_cell_number].classList.add('visited-right');
            gridcells[adjacent_cell_number].classList.add('visited-left');
            console.log(grid_cell_number);
            console.log('down');
        } else if (dx === -1) {
            const grid_cell_number = (current_vertex[0]) * cols + current_vertex[1];
            const adjacent_cell_number = grid_cell_number - 1;
            gridcells[grid_cell_number].classList.add('visited-left');
            gridcells[adjacent_cell_number].classList.add('visited-right');
            console.log(grid_cell_number);
            console.log('up');
        } else if (dy === 1) {
            const grid_cell_number = (current_vertex[0]-1) * cols + current_vertex[1] - 1;
            const adjacent_cell_number = grid_cell_number + cols;
            gridcells[grid_cell_number].classList.add('visited-down');
            gridcells[adjacent_cell_number].classList.add('visited-up');
            console.log(grid_cell_number);
            console.log('right');
        } else if (dy === -1) {
            const grid_cell_number = (current_vertex[0]) * cols + current_vertex[1];
            const adjacent_cell_number = grid_cell_number - cols;
            gridcells[grid_cell_number].classList.add('visited-up');
            gridcells[adjacent_cell_number].classList.add('visited-down');
            console.log(grid_cell_number);
            console.log('left');
        }

        previous_vertex = current_vertex;
        await delay(500);
    }
}

// Create the grid on page load
createGrid();
