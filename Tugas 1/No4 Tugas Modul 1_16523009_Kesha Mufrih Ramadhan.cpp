// NIM/Nama  : 16523009/Kesha Mufrih Ramadhan
// Deskripsi : Program yang mengidentifikasi apakah tahun yang diinput adalah tahun kabisat

#include <iostream>
using namespace std;

int main(){
    std::cout << "Tentukan tahun kabisat";
    std::cout << endl;
    int tahun;
    std:: cin >> tahun;

    if(tahun % 400 == 0){
        std::cout << "kabisat";
    }   else {
            if((tahun % 100 == 0) or (tahun % 100 != 0 and tahun % 4 !=0)){
                std::cout << "bukan kabisat";
            }
            else {
                std::cout << "kabisat";
            }

        }
}