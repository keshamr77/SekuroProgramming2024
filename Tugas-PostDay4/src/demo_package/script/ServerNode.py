#!/usr/bin/env python3

import rospy
from demo_package.srv import MagnitudeCalculation, MagnitudeCalculationResponse
from math import sqrt

def hitung_magnitude(req):
    magnitude = sqrt(req.komponenX**2 + req.komponenY**2 + req.komponenZ**2)

    rospy.loginfo("Menerima ingfo: X=%f, Y=%f, Z=%f", req.komponenX, req.komponenY, req.komponenZ)
    rospy.loginfo("Mengirim ingfo...")

    return MagnitudeCalculationResponse(magnitude)

def magnitude_server():
    rospy.init_node('server_node')
    s = rospy.Service('calculate_magnitude', MagnitudeCalculation, hitung_magnitude)
    rospy.loginfo("Siap menghitung magnitude.")
    rospy.spin()

if __name__ == "__main__":
    magnitude_server()
