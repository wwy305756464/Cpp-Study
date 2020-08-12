// minimal_controller_node:

#include<ros/ros.h>
#include<std_msgs/Float64.h>

std_msgs::Float64 g_velocity;
std_msgs::Float64 g_vel_cmd;
std_msgs::Float64 g_force;

void myCallbackVelocity(const std_msgs::Float64& message_holder) {
    ROS_INFO("received force value is: %f", message_holder.data);
    g_velocity.data = message_holder.data;
}

void myCallbackVelCmd(const std_msgs::Float64& message_holder) {
    ROS_INFO("received velocity command value is: %f", message_holder.data);
    g_vel_cmd.data = message_holder.data;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "minimal_controller");
    ros::NodeHandle nh;
    ros::Subscriber my_subscriber_object_1 = nh.subscribe("velocity", 1, myCallbackVelocity);
    ros::Subscriber my_subscriber_object_2 = nh.subscribe("vel_cmd", 1, myCallbackVelCmd);
    ros::Publisher my_publisher_object = nh.advertise<std_msgs::Float64>("force_cmd", 1);

    double Kv = 1.0;
    double dt_controller = 0.01;
    double sample_rate = 1.0/dt_controller;
    double vel_err = 0.0;
    g_velocity.data = 0.0;
    g_force.data = 0.0;
    g_vel_cmd.data = 0.0;

    ros::Rate naptime(sample_rate);

    while(ros::ok()) {
        vel_err = g_vel_cmd.data - g_velocity.data;
        g_force.data = Kv * vel_err;
        my_publisher_object.publish(g_force);

        ROS_INFO("force command = %f", g_force.data);
        ros::spinOnce();
        naptime.sleep();
    }
    
    return 0;
}