import os
from ament_index_python.packages import get_package_share_path
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration, Command
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    package_name = 'milo_sim'

    # Check if we're told to use sim time
    use_sim_time = LaunchConfiguration('use_sim_time')

    # Get the urdf/xacro file path
    path_to_urdf = get_package_share_path(package_name) / 'urdf' / 'milo.urdf.xacro'
    
    # Create a robot_state_publisher node
    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{
            'robot_description': ParameterValue(Command(['xacro ', str(path_to_urdf)]), value_type=str)
        }]
    )



    # Correct path to the world file
    world = get_package_share_path(package_name) / "worlds" / "grid.sdf"

    # Include Gazebo launch with correct world path
    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                str(get_package_share_path("ros_gz_sim") / "launch" / "gz_sim.launch.py")
            ]
        ),
        launch_arguments={"gz_args": f"-r -v 4 {world}"}.items(),
    )

    # Spawn the robot in Gazebo
    spawn_entity = Node(
        package="ros_gz_sim",
        executable="create",
        arguments=[
            "-name", "milo",
            "-topic", "/robot_description",
            "-x", "0",
            "-y", "0",
            "-z", "1.1",
        ],
        output="screen",
    )

    # Launch!
    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='true',
            description='Use sim time if true'),
        node_robot_state_publisher, gz_sim, spawn_entity
    ])
