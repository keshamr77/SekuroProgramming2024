// NIM/Nama  : 16523009/Kesha Mufrih Ramadhan
// Tanggal   : 9 November 2023
// Deskripsi : Program yang penerbangan pesawat berdasarkan kriteria

#include <iostream>
using namespace std;

// Algoritma program utama
int main() {
    std::string input;
    // Memulai loop yang menanyakan jenis pesawat
    while (true){
        std::cout << "Masukkan jenis pesawat : ";
        std::cin >> input;
        
        // Jika input "a"
        if (input ==  "a"){
            // Mencetak hitung mundur 3 2 1 
            for (int i = 3; i > 0; --i){
                // Setiap angka akan dicetak per baris baru
                std::cout << i << std::endl;
            }
            // Mencetak string "PESAWAT A BERANGKAT"
            std::cout << "PESAWAT A BERANGKAT" << std::endl;
        }
        // Jika input "b"
        else if (input == "b"){
            // Mencetak hitung mundur 5 4 3 2 1
            for (int i = 5; i > 0; --i){
                // Setiap angka akan dicetak per baris baru
                std::cout << i << std::endl;
            }
            // Mencetak string "PESAWAT B BERANGKAT"
           std::cout << "PESAWAT B BERANGKAT" << std::endl; 
        }
        // Jika input "o"
        else if (input == "o"){
            // Mencetak string "PENERBANGAN DITUTUP"
            std::cout <<"PENERBANGAN DITUTUP"<< std::endl;
            // Menyelesaikan program
            break;
        }
        // Jika ada input selain kriteria maka akan mencetak string "INPUT TIDAK VALID"
        else {
            std::cout<<"INPUT TIDAK VALID"<<std::endl;
        }
    }
}