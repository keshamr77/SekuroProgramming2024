// NIM/Nama : 16523009/Kesha Mufrih Ramadhan
// TUGAS PENDAHULUAN MODUL 3
// NOMOR 1

#include <iostream>
class LinearLine
{
private:
    float x1;
    float y1;
    float x2;
    float y2;

public:
    LinearLine (float x1, float y1, float x2, float y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    float gradient() {
        return (y2 - y1) / (x2 - x1);
    }

    float y_intercept() {
        return y1 -gradient() * x1;
    }

    LinearLine operator + (float a) {
        return LinearLine(x1 + a, y1, x2 + a, y2);
    }

    void printEquation() {
        std::cout << "y = " << gradient() <<"x + " << y_intercept() <<std::endl;
    }

    void printPoints() {
        std::cout << "(x1,y1) = " << "(" << x1 << "," << y1 << ")" << std::endl;
        std::cout << "(x2,y2) = " << "(" << x2 << "," << y2 << ")" << std::endl;
    }
};

int main()
{
    LinearLine line(1.0f, 8.0f, 2.0f, 3.0f); // inisialisasi objek line
    int a = 3; // nilai banyaknya penggeseran pada persamaan linear

    line.printPoints();
    std::cout << "Sehingga didapatkan" << std::endl;
    std::cout << "gradient = " << line.gradient() << std::endl;
    std::cout << "y_intercept = " << line.y_intercept() << std::endl;
    line.printEquation();

    line = line + a;
    std::cout << "Setelah digeser sejauh a, didapatkan persamaan baru:"<< std::endl;
    line.printEquation();


}
