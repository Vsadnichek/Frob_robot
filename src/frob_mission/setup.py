from setuptools import find_packages, setup

package_name = 'frob_mission'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/config', ['config/graph.yaml', 'config/mission_params.yaml']),
        ('share/' + package_name + '/launch', [
            'launch/mission.launch.py',
            'launch/planning.launch.py',
            'launch/simulation.launch.py',
        ]),
        ('share/' + package_name + '/worlds', [
            'worlds/city_polygon.sdf',
            'worlds/city_polygon_tb4.sdf',
        ]),
    ],
    install_requires=['setuptools', 'numpy'],
    zip_safe=True,
    maintainer='Alex Kulagin',
    maintainer_email='sashakulagin2007@gmail.com',
    description='City navigation mission: graph-based path planning and motion execution',
    license='Apache License 2.0',
    entry_points={
        'console_scripts': [
            'graph_navigator = frob_mission.graph_navigator:main',
            'graph_visualizer = frob_mission.graph_visualizer:main',
            'motion_executor = frob_mission.motion_executor:main',
            'topic_relay = frob_mission.topic_relay:main',
        ],
    },
)
