#include "ros/ros.h"
#include "demo_package/MagnitudeCalculation.h"
#include <cmath>

int main(int argc, char**argv){
    // Inisialisasi Node
    ros::init(argc,argv,"client_node");

    // Inisialisasi Handler Node
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<demo_package::MagnitudeCalculation>("MagnitudeCalculation");

    demo_package::MagnitudeCalculation srv;
    srv.request.komponenX = 1;
    srv.request.komponenY = 2;
    srv.request.komponenZ = 3;

    if(client.call(srv)) {
        ROS_INFO("Magnitude = %ld", srv.response.magnitude);
    }
    else {
        ROS_INFO("Waduh");
        return 1;
    }

    return 0;
}