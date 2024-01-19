// NIM/Nama : 16523009/Kesha Mufrih Ramadhan
// Deskripsi : Membuat fungsi yang berguna untuk menjumlahkan total dari elemen-elemen dalam array

#include <iostream>
using namespace std;
// Tidak boleh membuat global variable
// Buat Fungsi Disini
int jumlah(int arr[], int N){
    // Inisialisasi Variabel untuk menjumlahkan elemen-elemen dalam array
    int totalArr = 0;

    // Loop yang menghitung elemen array sampai panjangnya yang telah diinput sebelumnya
    for(int i = 0; i < N; ++i){
        totalArr += arr[i];
    }

    // Mengembalikan jumlah total yang telah dihitung oleh loop
    return totalArr;
}

// ALGORITMA UTAMA
int main(){
    int N; cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){cin>>arr[i];}
    cout<<jumlah(arr, N)<<endl;

}
