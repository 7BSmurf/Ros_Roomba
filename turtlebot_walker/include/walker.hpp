#pragma once


#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>

namespace sdw {

class Walker {
 private:

    double distance;
 public:

    Walker(ros::NodeHandle node);
    

    void laserCallback(const sensor_msgs::LaserScan::ConstPtr& data);
};
} // namespace sdw
