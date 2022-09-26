#pragma once


#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>

namespace sdw {
/**
 * @brief Walker class
 * **/
class Walker {
 private:
    /**
     * @brief Stores distance (in meters) from obstacle.
     * **/
    double distance;
 public:
    /**
     * @brief Walker class constructor.
     * @param node ROS Nodehandle
     * **/
    Walker(ros::NodeHandle node);
    
    /**
     * @brief Laserscan subscriber callback
     * @param data Single scan from a planar laser range finder
     * **/
    void laserCallback(const sensor_msgs::LaserScan::ConstPtr& data);
};
} // namespace sdw
