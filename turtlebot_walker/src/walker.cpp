

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>
#include "geometry_msgs/Twist.h"
#include "walker.hpp"

void sdw::Walker::laserCallback(const sensor_msgs::LaserScan::ConstPtr& data) {
    distance = data->ranges[180];
    ROS_INFO_STREAM("Distance avant obstacle : " << distance);
}

sdw::Walker::Walker(ros::NodeHandle node) {
    // ROS subscriber to LaserScan
    ros::Subscriber laserSubscriber = node.subscribe("/scan", 1000, &Walker::laserCallback, this);

    // ROS publisher to velocity topic
    ros::Publisher velocityPublisher = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);

    // Looprate of 4 Hz
    ros::Rate rate(4);

    while (ros::ok()) {
        // Define twist msg
        geometry_msgs::Twist twist;
        // Initialize to all zeros
        twist.linear.x = 0.0;
        twist.linear.y = 0.0;
        twist.linear.z = 0.0;
        twist.angular.x = 0.0;
        twist.angular.y = 0.0;
        twist.angular.z = 0.0;

        if (distance > 0.45) {
            ROS_INFO_STREAM("Le robot avance ...");
            twist.linear.x = -0.12;
        } else {
            ROS_INFO_STREAM("Le robot tourne ...");
            twist.angular.z = 1.5;
        }

        velocityPublisher.publish(twist);
        ros::spinOnce();
        rate.sleep();
    }
}
