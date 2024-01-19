#! /usr/bin/env python3
import rospy
from demo_package.msg import Topic

def pembicara() :
    dataDikirim = rospy.Publisher("mainTopic", Topic, queue_size = 10)

    rospy.init_node("Publisher", anonymous=True)

    rate=rospy.Rate(1)

    while not rospy.is_shutdown():
        dataVariabel = Topic()

        dataVariabel.usia = 1000
        dataVariabel.tinggi = 2.16
        dataVariabel.nama = "Raja Iblis"
        dataVariabel.kehadiran = False
    
        rospy.loginfo("INGFOKAN")

        dataDikirim.publish(dataVariabel)

        rate.sleep()

if __name__ == "__main__" :
    try :
        pembicara()
    except rospy.ROSInterruptException :
        pass