# turtlebot-walker
[![License:MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/nalindas9/turtlebot_walker/blob/Week12_HW/LICENSE)

Un Algorithme en C++ permettant de reproduire le mouvement d'un roomba avec un turtlebot3

## Dépendances

Les dépendances suivantes doivent être au préalable installées pour faire fonctionner ce packet
1. ROS Noetic
2. catkin 
3. Ubuntu 18.04 

## Installation
```
cd ~/catkin_ws/src
git clone --recursive https://github.com/7bsmurf/Ros_Roomba/turtlebot_walker.git
cd ..
catkin_make
```
## Lancement programme

1. Terminal 1:
```
roscore
```

2. Terminal 2:
```
cd catkin_ws
source devel/setup.bash
roslaunch turtlebot_walker turtlebot_walker.launch 
```
