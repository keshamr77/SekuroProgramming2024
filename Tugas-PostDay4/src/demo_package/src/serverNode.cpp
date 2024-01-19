#include "ros/ros.h"
#include "demo_package/MagnitudeCalculation.h"
#include <cmath>

bool magnitudeHitung(demo_package::MagnitudeCalculation::Request &req, demo_package::MagnitudeCalculation::Response &resp){
    resp.magnitude = std::sqrt(req.komponenX * req.komponenX + req.komponenY * req.komponenY + req.komponenZ * req.komponenZ);

    return true;
}

int main(int argc, char**argv){
    // Inisialisasi Node
    ros::init(argc,argv,"server_node");

    // Inisialisasi Handler Node
    ros::NodeHandle nh;

    // Inisialisasi Server dari Handler
    ros::ServiceServer server = nh.advertiseService("MagnitudeCalculation",magnitudeHitung);
    ROS_INFO("Siap menghitung magnitude capt!");
    ros::spin();

    return 0;
}