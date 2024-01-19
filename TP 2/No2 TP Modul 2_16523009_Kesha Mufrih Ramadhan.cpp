// NIM/Nama  : 16523009/Kesha Mufrih Ramadhan
// Deskripsi : Program menghitung luas lingkaran dengan mendaklarasikan suatu fungsi

#include <iostream>
using namespace std;

// Fungsi menghitung luas lingkaran
float luas(float r){
    // Inisialiasasi variabel konstan pi
    const float pi = 3.14;

    // Operasi untuk menghitung luas lingkaran
    float luasLingkaran = pi * r * r;

    // Mengembalikan nilai luas lingkaran
    return luasLingkaran;
}

// Algoritma utama
int main(){

    float r;
    cout << "Masukkan radius lingkaran: ";
    cin >> r;

    float hasilLuas = luas(r);

    cout <<"Luas lingkaran dengan radius " << r << " adalah : " << hasilLuas << endl;
}