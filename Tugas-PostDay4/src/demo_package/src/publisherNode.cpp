#include "ros/ros.h"
#include "demo_package/Topic.h"

int main(int argc, char**argv){
    ros::init(argc,argv,"publisherNode_cpp");

    ros::NodeHandle nh;

    ros::Publisher data_pub = nh.advertise<demo_package::Topic>("topikUtama",1000);

    ros::Rate loop_rate(1);

    while(ros::ok()){
        demo_package::Topic sendTopic;

        sendTopic.usia = 100;
        sendTopic.tinggi = 1.90;
        sendTopic.nama = "Muhammad Sumbul";
        sendTopic.kehadiran = true;

        ROS_INFO("Ingfo Aman Capt %s");

        data_pub.publish(sendTopic);

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}