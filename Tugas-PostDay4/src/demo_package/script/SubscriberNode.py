#! /usr/bin/env python3
import rospy
from demo_package.msg import Topic

def callback(data):
    # Mencetak pesan yang diterima
    rospy.loginfo("ABSENSI INSTITUT RUSDI BARBERSHOP:")
    rospy.loginfo("Usia: %ld" % data.usia)
    rospy.loginfo("Tinggi: %lf" % data.tinggi)
    rospy.loginfo("Nama: %s" % data.nama)
    rospy.loginfo("Kehadiran: %s" % ("Hadir" if data.kehadiran else "Tidak Hadir"))

def pendengar():
    # Inisialisasi Node
    rospy.init_node("subscriber",anonymous=True)

    # Inisialisasi Subscriber
    rospy.Subscriber("mainTopic",Topic,callback)

    rospy.spin()

if __name__ == "__main__":
    pendengar()