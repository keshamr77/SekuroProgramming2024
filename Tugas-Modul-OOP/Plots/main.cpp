#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include "pbPlots.hpp"
#include "supportLib.hpp"
using namespace std;

class Matrix
{
private:
    vector<vector<double>> v;
    int baris;
    int kolom;

public:
    // Constructor Matrix
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

    Matrix(const Matrix &MatrixLain)
    {
        v = MatrixLain.v;
        kolom = MatrixLain.kolom;
        baris = MatrixLain.baris;
    }

    // Fungsi penjumlahan matrix
    Matrix operator+(const Matrix &MatrixLain)
    {
        if (baris != MatrixLain.baris || kolom != MatrixLain.kolom)
        {
            std::cout << "The matrix dimension is not valid\n";
            return Matrix(1, 1);
        }

        vector<vector<double>> hasil(baris, vector<double>(kolom, 0));
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < kolom; j++)
            {
                hasil[i][j] = v[i][j] + MatrixLain.v[i][j];
            }
        }
        return Matrix(hasil);
    }

    // Fungsi pengurangan matrix
    Matrix operator-(const Matrix &MatrixLain)
    {
        if (baris != MatrixLain.baris || kolom != MatrixLain.kolom)
        {
            std::cout << "The matrix dimension is not valid\n";
            return Matrix(1, 1);
        }

        vector<vector<double>> hasil(baris, vector<double>(kolom, 0));
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < kolom; j++)
            {
                hasil[i][j] = v[i][j] - MatrixLain.v[i][j];
            }
        }
        return Matrix(hasil);
    }

    // Fungsi pengali matrix
    Matrix operator*(const Matrix &MatrixLain)
    {
        if (kolom != MatrixLain.baris)
        {
            std::cout << "Multiplication cannot be done. The number of columns in the first matrix should be equal to the number of rows in the second\n";
            return Matrix(1, 1);
        }

        vector<vector<double>> hasil(baris, vector<double>(MatrixLain.kolom, 0));
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < MatrixLain.kolom; j++)
            {
                double sum = 0;
                for (int k = 0; k < kolom; k++)
                {
                    sum += v[i][k] * MatrixLain.v[k][j];
                }
                hasil[i][j] = sum;
            }
        }
        return Matrix(hasil);
    }

    // Fungsi display matrix hasil
    void display() const
    {
        for (int i = 0; i < baris; ++i)
        {
            for (int j = 0; j < kolom; ++j)
            {
                std::cout << v[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // Operator kurung untuk mengakses elemen matrix
    double operator()(int i, int j) const
    {
        return v[i][j];
    }
};

class Swerve : public Matrix
{
private:
    double vx;
    double vy;
    double omega;
    double deltaTime;
    double rnx = 0.26363;
    double rny = 0.26363;
    Matrix matrixKecepatan;
    Matrix matrixPose;

public:
    // Constructor
    Swerve(double X, double Y, double Theta) : Matrix({{X}, {Y}, {Theta}}), vx(0), vy(0), omega(0), deltaTime(0.0), matrixKecepatan({{vx}, {vy}, {omega}}), matrixPose({{X}, {Y}, {Theta}}) {}

    // Fungsi untuk menghitung dan menyimpan nilai vx, vy, dan omega
    void velocityCommand(double vx, double vy, double omega)
    {
        // Inisialisasi vektor
        vector<vector<double>>input {{vx},{vy},{omega}};
        
        // Matriks transformasi
        Matrix komponenMatrix({{1, 0, -rny * sin(M_PI / 4),},
                               {0, 1, rnx * (cos(M_PI / 4))},
                               {1, 0, -rny * sin(M_PI / 4)},
                               {0, 1, rnx * (cos(M_PI / 4))},
                               {1, 0, -rny * sin(M_PI / 4)},
                               {0, 1, rnx * (cos(M_PI / 4))},
                               {1, 0, -rny * sin(M_PI / 4)},
                               {0, 1, rnx * (cos(M_PI / 4))}});

        // Matriks input
        Matrix matrixPengaliKecepatan({{vx}, {vy}, {omega}});

        // Menghitung hasil perkalian matriks
        matrixKecepatan = komponenMatrix * matrixPengaliKecepatan;
    }

    // Fungsi untuk mengupdate posisi chasis robot berdasarkan deltaTime
    void updatePose(double deltaTime)
    {
        // Matriks deltaT
        Matrix matrixDeltaT({{deltaTime},
                             {deltaTime},
                             {deltaTime}});

        // Menghitung perubahan posisi chasis robot berdasarkan rumus
        Matrix deltaPose = matrixKecepatan * matrixDeltaT;

        // Mengakumulasi perubahan posisi pada matrixPose
        matrixPose = matrixPose + deltaPose;
    }

    // Getter untuk mendapatkan nilai X
    double getX() const
    {
        return matrixPose(0, 0); // Kolom 0, Baris 0
    }

    // Getter untuk mendapatkan nilai Y
    double getY() const
    {
        return matrixPose(1, 0); // Kolom 0, Baris 1
    }

    // Getter untuk mendapatkan nilai Theta
    double getTheta() const
    {
        return matrixPose(2, 0); // Kolom 0, Baris 2
    }

    // Getter untuk mendapatkan nilai vx dari roda ke-n
    double getVxRodaN(int n) const
    {
        return matrixKecepatan(2 * (n - 1), 0); // Kolom 0, Baris 2n-2
    }

    // Getter untuk mendapatkan nilai vy dari roda ke-n
    double getVyRodaN(int n) const
    {
        return matrixKecepatan(2 * (n - 1) + 1, 0); // Kolom 0, Baris 2n-1
    }
};

// Mulai inisialisasi variabel untuk simulasi
// Fungsi untuk mencari vx
double vx(double T) 
{
 return 48 * cos(T) * pow(sin(T), 2);
}

// Fungsi untuk mencari vy
double vy(double T)
{
    return 4 * sin(4 * T) + 6 * sin(3 * T) + 10 * sin(2 * T) - 13 * sin(T);
}


// Program simulasi utama
int main()
{
    // Inisialisasi data waktu
    double T0 = 0.0;
    double Tt = 6.3;
    double dT = 0.01;

    // Inisialisasi data pose awal bersama dengan swerve
    double X0 = 0.0;
    double Y0 = 5.0;
    double theta0 = 0.0;
    Swerve swerveRobot(X0, Y0, theta0);

    // Vektor untuk menyimpan data posisi x dan y
    std::vector<double> poseX {X0};
    std::vector<double> poseY {Y0};
    std::vector<double> waktu {T0};

    // Vektor untuk menyimpan data kecepatan roda
    swerveRobot.velocityCommand(vx(0), vy(0), 0);
    std::vector<double> rodaV1;
    std::vector<double> rodaV2;
    std::vector<double> rodaV3;
    std::vector<double> rodaV4;

    // Loop yang memproses simulasi
    for(double T = T0 + dT; T <= Tt; T+=dT)
    {
        swerveRobot.velocityCommand(vx(T), vy(T), 0);
        swerveRobot.updatePose(dT);

        // Simpan data posisi
        poseX.push_back(swerveRobot.getX());
        poseY.push_back(swerveRobot.getY());
        waktu.push_back(T);

        // Simpan data kecepatan roda
        rodaV1.push_back(swerveRobot.getVxRodaN(1));
        rodaV2.push_back(swerveRobot.getVxRodaN(2));
        rodaV3.push_back(swerveRobot.getVxRodaN(3));
        rodaV4.push_back(swerveRobot.getVxRodaN(4));

    }

    // Grafik posisi y terhadap x
    StringReference *errorMessage1 = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference1 = CreateRGBABitmapImageReference();         
    DrawScatterPlot(imageReference1, 600, 400, &poseX, &poseY, errorMessage1);          
    std::vector<double> *pngdata1 = ConvertToPNG(imageReference1->image);     
    WriteToFile(pngdata1, "Grafik Posisi Y terhadap X.png");      
    DeleteImage(imageReference1->image); 

    // Grafik v1 terhadap waktu
    StringReference *errorMessage2 = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference2 = CreateRGBABitmapImageReference();
    DrawScatterPlot(imageReference2, 600, 400, &waktu, &rodaV1, errorMessage2);
    std::vector<double> *pngdata2 = ConvertToPNG(imageReference2->image);
    WriteToFile(pngdata2, "Grafik V1 terhadap waktu.png");
    DeleteImage(imageReference2->image);


    // Grafik v2 terhadap waktu
    StringReference *errorMessage3 = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference3 = CreateRGBABitmapImageReference();
    DrawScatterPlot(imageReference3, 600, 400, &waktu, &rodaV2, errorMessage3);
    std::vector<double> *pngdata3 = ConvertToPNG(imageReference3->image);
    WriteToFile(pngdata3, "Grafik V2 terhadap waktu.png");
    DeleteImage(imageReference3->image);
    
    // Grafik v3 terhadap waktu
    StringReference *errorMessage4 = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference4 = CreateRGBABitmapImageReference();
    DrawScatterPlot(imageReference4, 600, 400, &waktu, &rodaV3, errorMessage4);
    std::vector<double> *pngdata4 = ConvertToPNG(imageReference4->image);
    WriteToFile(pngdata4, "Grafik V3 terhadap waktu.png");
    DeleteImage(imageReference4->image);

    // Grafik v4 terhadap waktu
    StringReference *errorMessage5 = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference5 = CreateRGBABitmapImageReference();
    DrawScatterPlot(imageReference5, 600, 400, &waktu, &rodaV4, errorMessage5);
    std::vector<double> *pngdata5 = ConvertToPNG(imageReference5->image);
    WriteToFile(pngdata5, "Grafik V4 terhadap waktu.png");
    DeleteImage(imageReference4->image);
    
    return 0;
}

// Maaf kak saya tidak tahu letak kesalahannya dimana sehingga menghasilkan multiplication cannot be done