// NIM/Nama  : 16523009/Kesha Mufrih Ramadhan
// Deskripsi : Program yang mengidentifikasi apakah input merupakan bilangan prima

#include <iostream>
using namespace std;

int main(){
    int angka;
    std::cout << "Input satu angka bulat: ";
    std::cin >> angka;

    if(angka <= 1){
        cout << angka << " bukan bilangan prima.";
    }
    else {
        bool adlhPrima = true;
        for(int i = 2; i <= angka/2; ++i){
            if(angka % i == 0){
                adlhPrima = false;
                break;
            }
        }
        if(adlhPrima){
            cout << angka << " adalah bilangan prima";
        }
        else {
            cout << angka << " bukan bilangan prima";
        }
    }
}