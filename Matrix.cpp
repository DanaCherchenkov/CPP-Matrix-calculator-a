#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Matrix.hpp"

using namespace std;

namespace zich{

        /*
        Constructor
        */
        Matrix::Matrix(vector<double> myMatrix, size_t row, size_t col){}

        /*
        Functions for oparetion (+) 
        */
        Matrix operator+(const Matrix& m1, const Matrix& m2){return m1;}
        void operator+=(const Matrix& m1, const Matrix& m2){}
        Matrix operator+(const Matrix& m){return m;} //Unari - copy the matrix

        Matrix operator+(const Matrix& m, double scalar){return m;}
        Matrix operator+(double scalar, const Matrix& m){return m;}
        void operator+=(const Matrix& m, double scalar){}

        /*
        Functions for oparetion (-) 
        */
        Matrix operator-(const Matrix& m1, const Matrix& m2){return m1;}
        void operator-=(const Matrix& m1, const Matrix& m2){}
        Matrix operator-(const Matrix& m){return m;} //Unari *(-1)

        Matrix operator-(const Matrix& m, double scalar){return m;}
        Matrix operator-(double scalar, const Matrix& m){return m;} //??
        void operator-=(const Matrix& m, double scalar){}

        /*
        Functions for oparetion (*) 
        */           
        Matrix operator*(const Matrix& m1, const Matrix& m2){return m1;}
        void operator*=(Matrix& m1, const Matrix& m2){}

        Matrix operator*(const Matrix& m, double scalar){return m;}
        Matrix operator*(double scalar, const Matrix& m){return m;}
        void operator*=(Matrix& m, int scalar){}
        
        /*
        Functions for comparisons
        */
        bool operator<(const Matrix& m1, const Matrix& m2){return true;}
        bool operator<=(const Matrix& m1, const Matrix& m2){return true;}
        bool operator>(const Matrix& m1, const Matrix& m2){return true;}
        bool operator>=(const Matrix& m1, const Matrix& m2){return true;}
        bool operator==(const Matrix& m1, const Matrix& m2){return true;}
        bool operator!=(const Matrix& m1, const Matrix& m2){return true;}

        /*
        Functions for ++1 / --1
        */
        void operator++(Matrix& m){}
        void operator--(Matrix& m){}

        /*
        Functions for input and output 
        */
        istream& operator>>(istream& in, const Matrix& m){return in;}
        ostream& operator<<(ostream& out, const Matrix& m){return out;}
}