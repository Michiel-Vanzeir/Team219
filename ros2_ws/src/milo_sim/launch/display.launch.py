from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    ld = LaunchDescription()

    robot_package_path = FindPackageShare('milo_sim')
    robot_model_file = PathJoinSubstitution(['urdf', 'milo.urdf.xacro'])
    rviz_file_path = PathJoinSubstitution([robot_package_path, 'rviz', 'robot_view.rviz'])

    # Launch argument to enable or disable the joint state publisher GUI
    gui_flag = DeclareLaunchArgument(name='use_gui', default_value='true', choices=['true', 'false'],
                                     description='Enable joint state publisher GUI')
    ld.add_action(gui_flag)

    # Launch argument for specifying the RViz configuration file
    rviz_config_arg = DeclareLaunchArgument(name='rviz_file', default_value=rviz_file_path,
                                            description='Path to RViz configuration file')
    ld.add_action(rviz_config_arg)

    # Launch argument for specifying the robot model file
    model_file_arg = DeclareLaunchArgument(name='robot_model', default_value=robot_model_file,
                                           description='Path to the robot URDF file')
    ld.add_action(model_file_arg)

    # Include the display launch file from the 'urdf_launch' package
    ld.add_action(IncludeLaunchDescription(
        PathJoinSubstitution([FindPackageShare('urdf_launch'), 'launch', 'display.launch.py']),
        launch_arguments={
            'urdf_package': 'milo_sim',
            'urdf_package_path': LaunchConfiguration('robot_model'),
            'rviz_config': LaunchConfiguration('rviz_file'),
            'jsp_gui': LaunchConfiguration('use_gui')}.items()
    ))

    return ld