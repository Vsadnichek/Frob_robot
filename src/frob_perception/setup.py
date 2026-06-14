from setuptools import find_packages, setup

package_name = 'frob_perception'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/config', ['config/perception_params.yaml']),
        ('share/' + package_name + '/launch', ['launch/perception.launch.py']),
    ],
    install_requires=['setuptools', 'numpy'],
    zip_safe=True,
    maintainer='Alex Kulagin',
    maintainer_email='sashakulagin2007@gmail.com',
    description='Camera driver and perception (line detection, sign detection)',
    license='Apache License 2.0',
    entry_points={
        'console_scripts': [
            'camera_node = frob_perception.camera_node:main',
        ],
    },
)
