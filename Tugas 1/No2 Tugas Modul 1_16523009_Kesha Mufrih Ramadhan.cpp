// NIM/Nama  : 16523009/Kesha Mufrih Ramadhan
// Deskripsi : Program menghitung rata-rata bilangan

#include <iostream>
using namespace std;

int main(){
    int jumlahBilangan;
    std::cout << "Jumlah bilangan : ";
    std::cin >> jumlahBilangan;

    float total;
    for(int i = 1; i <= jumlahBilangan; ++i){
        float n;
        std::cout << "Bilangan " << i << " : ";
        std::cin >> n;
        total += n;
    }

    float ratarata = total/jumlahBilangan;
    std::cout<< "RATA-RATA : " << ratarata;
}