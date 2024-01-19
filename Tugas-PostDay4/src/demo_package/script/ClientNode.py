#!/usr/bin/env python3

import rospy
from demo_package.srv import MagnitudeCalculation, MagnitudeCalculationResponse

def magnitude_client():
    rospy.init_node('client_node')
    rospy.wait_for_service('calculate_magnitude')

    try:
        calculate_magnitude = rospy.ServiceProxy('calculate_magnitude', MagnitudeCalculation)

        response = calculate_magnitude(1.0, 2.0, 3.0)

        rospy.loginfo("Ingfo dari server: Magnitude=%f", response.magnitude)

    except rospy.ServiceException as e:
        rospy.logerr("Gagal memanggil service: %s", e)

if __name__ == "__main__":
    magnitude_client()
