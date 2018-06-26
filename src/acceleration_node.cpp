#include "ros/ros.h"
#include "geometry_msgs/Accel.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "jiro_acceleration");
    ros::NodeHandle ros_node_handle;
    ros::Publisher ros_publisher = ros_node_handle.advertise<geometry_msgs::Accel>("acceleration", 1000);
    ros::Rate loop_rate(10);
    
    srand(time(0));

    ros::Rate ros_rate(10);
    
    while(ros::ok())
    {
        geometry_msgs::Accel acceleration_msg;
        acceleration_msg.linear.x = double(rand())/double(RAND_MAX);
        acceleration_msg.angular.z = 2 * double(rand())/double(RAND_MAX) - 1;
        ros_publisher.publish(acceleration_msg);
        
        ROS_INFO_STREAM("Acceleration: " 
            << " linear x " << acceleration_msg.linear.x 
            << " angular z " << acceleration_msg.angular.z
        );
        
        ros::spinOnce();
        ros_rate.sleep();        
    }
}