// NIM/Nama : 16523009/Kesha Mufrih Ramadhan
// TUGAS PENDAHULUAN MODUL 3
// NOMOR 2

#include <iostream>
class Shape
{
    protected:
        float area;
        float keliling;

    public:
        virtual float calculateArea() { return 0; }
        virtual float calculateKeliling() { return 0; }
};

class Rectangle : public Shape
{
    private :
        float lebar;
        float tinggi;
    
    public :
        Rectangle(float l, float t){
            this->lebar = l;
            this->tinggi = t;
        }

    float calculateArea(){
        area = lebar * tinggi;
        return area;
    }

    float calculateKeliling(){
        keliling = 2 * (lebar + tinggi);
        return keliling;
    }

};

int main()
{
    Rectangle rect (5.0, 4.0);
    Shape* shape1 = &rect;

    float area = shape1->calculateArea();
    float keliling = shape1->calculateKeliling();

    std::cout << "Luas = " << area << std::endl;
    std::cout << "Keliling = " << keliling << std::endl;

return 0;
}