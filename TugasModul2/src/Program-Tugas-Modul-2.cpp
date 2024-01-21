// NIM/Nama : 16523009/Kesha Mufrih Ramadhan
// Deskripsi : Tugas Post-Day 2 SEKURO 2024

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

// Deklarasi variabel posisi drone
double X_Drone = 0.00;
double Y_Drone = 0.00;

// Maksimum dari panjang array history
const int maxPanjangHistori = 100;

// Array untuk menyimpan histori pada koordinat X dan Y
double histori_X[maxPanjangHistori];
double histori_y[maxPanjangHistori];
int indexHistoriGerakan = 0;

// Fungsi lokasi()
void lokasi(){
    cout << "Drone sekarang berada pada titik : (" << X_Drone << "," << Y_Drone << ")" << endl;
}

// Fungsi gerak()
void gerak(double x, double y){

    // Menambahkan hasil gerakan pada histori gerakan
    if (indexHistoriGerakan < maxPanjangHistori){
        histori_X[indexHistoriGerakan] = X_Drone;
        histori_y[indexHistoriGerakan] =Y_Drone;
        indexHistoriGerakan++;
    }

    // Menggerakkan drone berdasarkan input gerakan setiap sumbu
    X_Drone += x;
    Y_Drone += y;
}

// Fungsi gerak_2()
void gerak_2(double v, double t, double theta){

    // Menambahkan hasil gerakan pada histori gerakan
    if (indexHistoriGerakan < maxPanjangHistori){
        histori_X[indexHistoriGerakan] = X_Drone;
        histori_y[indexHistoriGerakan] =Y_Drone;
        indexHistoriGerakan++;
    }

    // Menggerakkan drone berdasarkan input kecepatan waktu dan sudut
    X_Drone += v * t * cos(theta * M_PI/180);
    Y_Drone += v * t * sin(theta * M_PI/180);
}

// Fungsi undo()
void undo(){

    // Undo dapat dilakukan jika index histori diatas 0
    if (indexHistoriGerakan > 0){
        indexHistoriGerakan--;
        X_Drone = histori_X[indexHistoriGerakan];
        Y_Drone = histori_y[indexHistoriGerakan];
        cout << "Undo berhasil!" << endl;
    }

    else {
        cout << "Tidak dapat undo!" << endl;
    }
}


// ALGORITMA PROGRAM UTAMA
int main(){

    // Inisialisasi variabel
    int choice, mode_gerak;
    double x , y, v, t, theta ;



    // Memulai loop interface program dimana input 3 akan membuat program berhenti
    while(choice != 4) {

        //Interface dari "Drone Control"
        cout << "[Drone Control Interface]" << endl;
        cout << "1. Lokasi Drone Sekarang" << endl;
        cout << "2. Gerakkan Drone"<< endl;
        cout << "3. Undo Gerakan Drone" << endl;
        cout << "4. Keluar Dari Program" << endl;
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

        // Menjalankan fungsi undo
        else if (choice == 3){
            undo();
        }
        // Menghentikan program
        else if (choice == 4){
            cout << "[Program Selesai]" << endl;
        }

        // Jika input selain 1,2,3,4
        else {
            cout << "Input tidak valid, silahkan coba lagi" << endl;
        }  
    }
}