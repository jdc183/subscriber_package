#include "ros/ros.h"
#include "std_msgs/String.h"
#include "publisher_package/topic_name.h"

//Method called upon receipt of message
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
	//Initialize the ros node
	ros::init(argc, argv, "subscriber_node");
	ros::NodeHandle n;
	
	//Set up the chatterCallback to handle the event
	ros::Subscriber sub = n.subscribe(topic_name, 1000, chatterCallback);
	
	//Pump the callbacks!
	ros::spin();
	
	return 0;
}
