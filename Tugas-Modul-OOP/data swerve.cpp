#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
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

    // Operator penjumlahan matrix
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

    // Operator pengurangan matrix
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

    // Operator pengali matrix
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
        // Matriks transformasi
        Matrix komponenMatrix({{1, 0, -rny * sin(M_PI / 4)},
                               {0, 1, rnx * cos(M_PI / 4)},
                               {1, 0, -rny * sin(M_PI / 4)},
                               {0, 1, rnx * cos(M_PI / 4)},
                               {1, 0, -rny * sin(M_PI / 4)},
                               {0, 1, rnx * cos(M_PI / 4)},
                               {1, 0, -rny * sin(M_PI / 4)},
                               {0, 1, rnx * cos(M_PI / 4)}});

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


int main()
{
    // Inisialisasi data waktu
    double T0 = 0.0;
    double T = 6.3;
    double deltaTime = 0.01;

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
    while (T0 <= T)
    {
        swerveRobot.velocityCommand(vx(T0), vy(T0), 0);
        swerveRobot.updatePose(deltaTime);

        // Simpan data posisi
        poseX.push_back(swerveRobot.getX());
        poseY.push_back(swerveRobot.getY());

        // Simpan data kecepatan roda
        rodaV1.push_back(swerveRobot.getVxRodaN(1));
        rodaV2.push_back(swerveRobot.getVxRodaN(2));
        rodaV3.push_back(swerveRobot.getVxRodaN(3));
        rodaV4.push_back(swerveRobot.getVxRodaN(4));


        // Menampilkan data masing-masing roda
        for (int i = 1; i <= 4; ++i)
        {
            double Vxn = swerveRobot.getVxRodaN(i);
            double Vyn = swerveRobot.getVyRodaN(i);
            double kecepatanRoda= std::sqrt(pow(Vxn , 2) +pow(Vyn, 2));

            std::cout << "Kecepatan " << "Roda" << " ke-" << i << " = "<< kecepatanRoda << "\n";
        }
        std::cout << "Posisi X: " << poseX.back() << ", Posisi Y: " << poseY.back() << "\n";
        std::cout << "-----------------\n";

        T0 += deltaTime;
    }

    return 0;
}

