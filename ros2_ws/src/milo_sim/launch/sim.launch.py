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
    path_to_urdf = get_package_share_path(package_name) / 'urdf' / 'milo_circular.urdf.xacro'
    
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
            "-y", "0.15",
            "-z", "0.3",
        ],
        output="screen",
    )

    # LDR data topics
    ldr_topics = ['/milo/ldr1','/milo/ldr2','/milo/ldr3','/milo/ldr4','/milo/ldr5','/milo/ldr6','/milo/ldr7','/milo/ldr8']
    # ROS-Gazebo bridge for LDR sensor data
    ldr_bridges = [Node(
        package='ros_gz_bridge', 
        executable='parameter_bridge', 
        arguments=[f'{topic}@sensor_msgs/msg/Image@gz.msgs.Image']) for topic in ldr_topics]

    # Twist bridge for actuation between ROS and Gazebo
    motor_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/model/milo/cmd_vel@geometry_msgs/msg/Twist@gz.msgs.Twist']
    )

    # LDR readings processor to convert the images to a single intensity value
    ldr_processor = Node(
        package='milo_sensor_data',
        executable='ldr_data_processor'
    )

    # Main controller & decision maker for gridpoint detection, calibration, etc. 
    main_controller = Node(
        package='milo_control',
        executable='maincontroller'
    )

    # PID controller that uses the data from the ldr_processor
    pid_controller = Node(
        package='milo_control',
        executable='pidcontroller'
    )

    # Motor controller, converts the PID output to a Twist msg for Gazebo
    motor_controller = Node(
        package='milo_motion_control',
        executable='motorcontroller'
    )

    # Launch!
    launch_items = [
    DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use sim time if true'
    ), node_robot_state_publisher, gz_sim, spawn_entity, motor_bridge, ldr_processor, main_controller, pid_controller, motor_controller]
    launch_items.extend(ldr_bridges)

    return LaunchDescription(launch_items)