#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
    private :
        vector<vector<double>> v;
        int baris;
        int kolom;

    public :
        // Constructor
        Matrix(int baris, int kolom)
        {
            this->baris = baris;
            this->kolom = kolom;
            v = vector<vector<double>>(baris, vector<double>(kolom, 0));
        }
        
        Matrix(const vector<vector<double>> v) 
        {
            this->v = v;
            this->baris = v.size();
            this->kolom = v[0].size();
        }

        Matrix(const Matrix & MatrixLain)
        {
            v = MatrixLain.v;
            kolom = MatrixLain.kolom;
            baris = MatrixLain.baris;
        }

        Matrix operator+(const Matrix & MatrixLain)
        {

            if(baris != MatrixLain.baris || kolom != MatrixLain.kolom)
            {
                std::cout << "The matrix dimension is not valid\n";
                return Matrix(1,1);
            }

            vector<vector<double>> hasil(baris, vector<double>(kolom, 0));
            for(int i = 0; i < baris; i++)
            {
                for(int j = 0; j < kolom; j++)
                {
                    hasil[i][j] = v[i][j] + MatrixLain.v[i][j];
                }
            }
            return Matrix(hasil);
        }

        Matrix operator-(const Matrix & MatrixLain)
        {

            if(baris != MatrixLain.baris || kolom != MatrixLain.kolom)
            {
                std::cout << "The matrix dimension is not valid\n";
                return Matrix(1,1);
            }

            vector<vector<double>> hasil(baris, vector<double>(kolom, 0));
            for(int i = 0; i < baris; i++)
            {
                for(int j = 0; j < kolom; j++)
                {
                    hasil[i][j] = v[i][j] - MatrixLain.v[i][j];
                }
            }
            return Matrix(hasil);
        }

        Matrix operator*(const Matrix & MatrixLain)
        {

            if(kolom != MatrixLain.baris)
            {
                std::cout << "“Multiplication cannot be done. The number of columns in the first matrix should be equal to the number of rows in the second\n";
                return Matrix(1,1);
            }

            vector<vector<double>> hasil(baris, vector<double>(kolom, 0));
            for(int i = 0; i < baris; i++)
            {
                for(int j = 0; j < MatrixLain.kolom; j++)
                {
                    double sum = 0;
                    for(int k = 0; k < kolom;  k++)
                    {
                        sum += v[i][k] * MatrixLain.v[k][j];
                    }
                    hasil[i][j] = sum;
                }
            }
            return Matrix(hasil);
        }

        void display() const{
            for(int i = 0; i < baris; ++i)
            {
                for(int j = 0; j < kolom; ++j)
                {
                    std::cout << v[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
};

int main()
{
    Matrix A({{1, 2, 3}, {2, 3, 1}});
    Matrix B({{0, 2, 4}, {1, 2, 5}, {8, 2, 1.2}});
    Matrix C(2, 3);

    std::cout << "Matrix A\n";
    A.display();
    std::cout << "Matrix B\n";
    B.display();
    std::cout << "Matrix C\n";
    C.display();

    Matrix C1 = A + C;     
    std::cout << "Matrix C1\n";     
    C1.display();     
    std::cout << '\n';  

    Matrix C2 = A - C;     
    std::cout << "Matrix C2\n";     
    C2.display();     
    std::cout << '\n';   

    Matrix C3 = A * B;     
    std::cout << "Matrix C3\n";     
    C3.display();     
    std::cout << '\n'; 

    Matrix C4 = B * A;     
    std::cout << "Matrix C4\n";     
    C4.display();     
    std::cout << '\n';
 
    return 0; 
}