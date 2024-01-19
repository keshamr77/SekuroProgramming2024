// NIM/Nama  : 16523009/Kesha Mufrih Ramadhan
// Deskripsi : Program mencari bilangan genap dari range "a" dan "b"

#include <iostream>
using namespace std;

int main(){
    int a, b;
    std :: cin >> a >> b;

    for(int i = a; i <= b;++i){
        if(i % 2 == 0){
            std::cout << i << " ";
        }
    }
}