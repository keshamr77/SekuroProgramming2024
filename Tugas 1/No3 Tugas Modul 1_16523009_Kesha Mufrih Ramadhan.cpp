// NIM/Nama  : 16523009/Kesha Mufrih Ramadhan
// Deskripsi : Program membentuk segitiga dari input angka

#include <iostream>
using namespace std;

int main(){
    int n;
    std::cin >> n;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            std::cout << "*";
        }
        std::cout << endl;
    }

    for(int i = n - 1; i >= 1; --i){
        for(int j = 1; j <= i; ++j){
            std::cout << "*";
        }
        std::cout << endl;
    }
}