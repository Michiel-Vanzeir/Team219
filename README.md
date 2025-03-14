
# Milo
Milo is an autonomous line-following robot designed to navigate a grid, pick up green towers at specific grid points, and avoid red towers. It uses a backtracking algorithm to calculate the shortest path while following the black gridlines. 
# Table of Contents
   * [Getting started](#getting-started)
     * [Prerequisites](#prerequisites)
     * [Installation](#installation)

## Getting Started

Setting up the software is quite simple, for the CAD drawings and parts list, please refer to the [TODO] folder. This project utilizes a Raspberry Pi Pico WH with circuitpython installed, the corresponding code can be found in the /pico folder. The website frontend is custom-coded with HTML, CSS and the Bootstrap 4 framework. Its backend consists of a Javascript server which communicates with two different python servers; one for the backtracking algorithm and one for real-time communication with Milo. The main code for the website can be found in the /app and /server folder. The /ros2_ws folder consists of everything ROS (Robotics Operating System) related, such as the Gazebo simulation for the simulated version of the linefollowing algorithm, as well as a trained reinforcement learning agent. 

### Prerequisites

To run the website, make sure you have both Javascript (Node.js) and Python installed. Other than that, this project uses the ROS2 Jazzy distribution along with Gazebo Harmonic. More info regarding the installation can be found [here](https://docs.ros.org/en/jazzy/index.html) and [here](https://gazebosim.org/docs/harmonic/install/), respectively. If you are a Windows user, using a dualboot system or WSL2 is recommended, to install WSL2, please consult the [installation guide](https://learn.microsoft.com/en-us/windows/wsl/install), we strongly recommended using the Ubuntu 24.04 distro. 
 
### Installation

Installing the codebase for local use can easily be done as follows:

1. Clone the repo
   ```sh
   git clone https://github.com/Michiel-Vanzeir/Team219.git
   ```
2. CD into it (Linux)
   ```sh
   cd Team219
   ```
3. Install NPM packages for the website backend
   ```sh
   npm install
   ```
4. Install the Python dependencies
   ```py
   pip install -r requirements.txt
   ```
5. Install all ROS and Gazebo dependencies (Linux)
   ```
    sudo sh -c 'echo "deb [arch=$(dpkg --print-architecture)] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'
    curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
    sudo apt-get update
   ```
   ```
   sudo apt install ros-jazzy-ros-gz
   ```
6. Build and source the ROS packages
   ```
   cd ros2_ws/
   colcon build 
   source install/setup.bash
   echo "source ~/install/setup.bash" >> ~/.bashrc (Optional: this will be executed every time you open a terminal)
   ```
## To do 
- Add Usage section to README.MD
