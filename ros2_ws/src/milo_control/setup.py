from setuptools import find_packages, setup

package_name = 'milo_control'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='michiel',
    maintainer_email='michiel@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
          'maincontroller = milo_control.main_control:main',
          'pidcontroller = milo_control.PID_controller:main'
        ],
    },
)
