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
    console.log("Sent grid parameters: Rows: ${rows}, Cols: ${cols}");
}

// Listens for shortest path from python
socket.on('navigation_data', (data) => {
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
    console.log(`Creating grid with Rows: "+ rows + " Columns: ${cols}`);

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

// Create the grid on page load
createGrid();
