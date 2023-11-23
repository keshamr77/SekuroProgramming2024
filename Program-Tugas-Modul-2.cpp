// NIM/Nama : 16523009/Kesha Mufrih Ramadhan
// Deskripsi : Tugas Post-Day 2 SEKURO 2024

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// Deklarasi variabel posisi drone
double X_Drone = 0.00;
double Y_Drone = 0.00;

// Fungsi lokasi()
void lokasi(){
    cout << fixed << setprecision(2);
    cout << "Drone sekarang berada pada titik : (" << X_Drone << "," << Y_Drone << ")" << endl;
}

// Fungsi gerak()
void gerak(double x, double y){
    X_Drone += x;
    Y_Drone += y;
}

// Fungsi gerak_2()
void gerak_2(double v, double t, double theta){
    X_Drone += v * t * cos(theta * M_PI/180);
    Y_Drone += v * t * sin(theta * M_PI/180);
}


// ALGORITMA PROGRAM UTAMA
int main(){

    // Inisialisasi variabel
    int choice;
    double x , y, v, t, theta ;
    int mode_gerak;

    // Menampilkan interface program
    cout << "[Drone Control Interface]" << endl;
    cout << "1. Lokasi Drone Sekarang" << endl;
    cout << "2. Gerakkan Drone"<< endl;
    cout << "3. Keluar Dari Program" << endl;

    // Memulai loop interface program dimana input 3 akan membuat program berhenti
    while(choice != 3) {

          // Menerima input dari pengguna
        cout << "Masukkan pilihan anda: ";
        cin >> choice;

        // Mengoutput lokasi drone menggunakan fungsi lokasi()
        if (choice == 1){
            lokasi();
        }

        // Membuat drone bergerak menggunakan fungsi gerak()
        else if (choice == 2){

            // Memilih mode bagaimana drone bergerak dikarenakan ada dua fungsi gerak
            cout << "[Pilihan Mode Drone Bergerak]" << endl;
            cout << "1. Drone bergerak terhadap input sumbu x dan y" << endl;
            cout << "2. Drone bergerak terhadap input kecepatan, waktu tempuh, dan sudut pergerakkan" << endl;
            cout << "Masukkan mode pilihan anda : ";
            cin >> mode_gerak;

                // Untuk mode bergerak terhadap input sumbu x dan y (fungsi gerak())
                if (mode_gerak == 1) {
                    cout << "Masukkan gerakkan drone pada sumbu x dan y : ";
                    cin >> x >> y;
                    gerak(x,y);
                }

                // Untuk mode bergerak terhadap input kecepatan, waktu dan sudut dari gerakan drone (fungsi gerak_2())
                else if (mode_gerak == 2){
                    cout << "Masukkan kecepatan, waktu tempuh, dan sudut pergerakkan drone : ";
                    cin >> v >> t >> theta;
                    gerak_2(v, t, theta);
                }
        }

        // Menghentikan program
        else if (choice == 3){
            cout << "[Program Selesai]" << endl;
        }

        // Jika input selain 1,2,3
        else {
            cout << "Input tidak valid, silahkan coba lagi" << endl ;
        }  
    }
}