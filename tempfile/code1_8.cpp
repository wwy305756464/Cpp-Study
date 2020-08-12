// minimal_simulator_node:
// 一个节点同时充当publisher和subscriber

#include<ros/ros.h>
#include<std_msgs/Float64.h>

std_msgs::Float64 g_velocity;
std_msgs::Float64 g_force;

void myCallback(const std_msgs::Float64& message_holder) {
    ROS_INFO("received force value is: %f", message_holder.data);
    g_force.data = message_holder.data;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "minimal_simulator");
    ros::NodeHandle nh;
    ros::Subscriber my_subscriber_object = nh.subscribe("force_cmd", 1, myCallback);
    ros::Publisher my_publisher_object = nh.advertise<std_msgs::Float64>("velocity", 1);

    double mass = 1.0;
    double dt = 0.01;
    double sample_rate = 1.0/dt;
    g_velocity.data - 0.0;
    g_force.data = 0.0;

    ros::Rate naptime(sample_rate);

    while(ros::ok()) {
        g_velocity.data = g_velocity.data + (g_force.data/mass) * dt;
        my_publisher_object.publish(g_velocity);

        ROS_INFO("velocity = %f", g_velocity.data);
        ros::spinOnce();
        naptime.sleep();
    }

    return 0;
}