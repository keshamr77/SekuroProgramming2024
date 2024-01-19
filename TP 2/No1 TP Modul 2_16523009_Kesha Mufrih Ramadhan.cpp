// NIM/Nama  : 16523009/Kesha Mufrih Ramadhan
// Deskripsi : Program array

#include <iostream>
using namespace std;

int main(){
    const int  panjang_array = 10;

    int arr1[panjang_array], arr2[panjang_array];

    // Input angka angka untuk masuk ke arr1
    for(int i = 0; i < 10; ++i){
        cin >> arr1[i];
    }

    // Input angka angka untuk masuk ke arr2
    for(int i = 0; i < 10; ++i){
        cin >> arr2[i];
    }
    
    cout << endl;

    // Menjumlahkan setiap elemen array
    for(int i = 0; i < 10; ++i){
        cout << arr1[i] + arr2[i] << " ";
    }

}