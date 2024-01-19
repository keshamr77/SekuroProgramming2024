#include "ros/ros.h"
#include "demo_package/Topic.h"

void callback(const demo_package::Topic::ConstPtr &psn){
    ROS_INFO("\nIngfo Diterima Capt\n");
    ROS_INFO("Umur : %ld\n", psn->usia);
    ROS_INFO("Tinggi : %lf\n", psn->tinggi);
    ROS_INFO("Nama : %s\n", psn->nama.c_str());
    ROS_INFO("Hadir : %s\n", (psn->kehadiran ? "Hadir" : "Tidak Hadir"));
}

int main(int argc, char ** argv){
    ros::init(argc,argv,"subscriberNode");

    ros::NodeHandle nh;

    ros::Subscriber data_subs = nh.subscribe("topikUtama",1000,callback);

    ros::spin();

    return 0;
}