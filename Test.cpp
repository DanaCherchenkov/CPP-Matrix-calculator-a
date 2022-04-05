#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Matrix.hpp"
#include "doctest.h"
#include <ctime>

using namespace std;
using namespace zich;

TEST_CASE("oparetion (+)"){
    //test for(+=)
    for(double i = 0; i < 50; i++){
        vector<double> arr = {i, i, i, i};
        vector<double> arr1 = {i+2, i+2, i+2, i+2};
        vector<double> arr2 = {10, 10, 10, 10};
        vector<double> arr3 = {i+12, i+12, i+12, i+12};
        Matrix mat{arr, 2, 2};
        Matrix mat1{arr1, 2, 2};
        Matrix mat2{arr2, 2, 2};
        Matrix mat3{arr3, 2, 2};
        mat += 2; 
        CHECK(mat == mat1); //Matrix += scalar
        mat += mat2;
        CHECK(mat == mat3); //Matrix += Matrix
    }

    //test for (+)
    for(double i = 0; i < 50; i++){
        vector<double> arr = {i, i, i, i};
        vector<double> arr1 = {i+2, i+2, i+2, i+2};
        vector<double> arr2 = {2, 2, 2, 2};
        Matrix mat{arr, 2, 2};
        Matrix mat1{arr1, 2, 2};
        Matrix mat2{arr2, 2, 2};
        CHECK(mat1 == mat + 2); //Matrix + scalar
        CHECK(mat1 == 2 + mat); //scalar + Matrix
        CHECK(mat + mat2 == mat1); //Matrix + Matrix
    }

    //test for (+) unari
    for(double i = 0; i < 50; i++){
        vector<double> arr = {i, 0, i, 0, i, 0, i, 0, i};
        Matrix mat{arr, 3, 3};
        CHECK(mat == mat);
    }
}

TEST_CASE("oparetion (-)"){
    //test for (-=)
    for(double i = 5; i < 50; i++){
        vector<double> arr = {i, i, i, i, i+1, i+1, i+1};
        vector<double> arr1 = {i-3, i-3, i-3, i-3, i-3, i-3, i-3, i-3, i-3};
        vector<double> arr2 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        vector<double> arr3 = {i-4, i-4, i-4, i-4, i-4, i-4, i-4, i-4, i-4};
        Matrix mat{arr, 3, 3};
        Matrix mat1{arr1, 3, 3};
        Matrix mat2{arr2, 3, 3};
        Matrix mat3{arr3, 2, 3};
        mat -= 3; 
        CHECK(mat == mat1); //Matrix -= scalar
        mat -= mat2;
        CHECK(mat == mat3); //Matrix -= Matrix
    }

    //test for (-)
    for(double i = 10; i < 50; i++){
        vector<double> arr = {i, i, i, i};
        vector<double> arr1 = {i-2, i-2, i-2, i-2};
        vector<double> arr2 = {10, 10, 10, 10};
        vector<double> arr3 = {i-10, i-10, i-10, i-10};
        Matrix mat{arr, 2, 2};
        Matrix mat1{arr1, 2, 2};
        Matrix mat2{arr2, 2, 2};
        Matrix mat3{arr2, 2, 2};
        CHECK(mat1 == mat - 2); //Matrix - scalar
        CHECK(mat1 == 2 - mat); //scalar - Matrix
        CHECK(mat - mat2 == mat3); //Matrix - Matrix
    }

    //test for (-) unari
    for(double i = 0; i < 50; i++){
        vector<double> arr = {i, 0, i, 0, i, 0, i, 0, i};
        Matrix mat{arr, 3, 3};
        CHECK(mat == -(mat));
    }
}

TEST_CASE("oparetion (*)"){
    //test for (*=)
    for(double i = 0; i < 50; i++){
        vector<double> arr = {0, 0, i, 0, i, 0, i, 0, 0};
        vector<double> arr1 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        Matrix mat{arr, 3, 3};
        Matrix mat1{arr1, 3, 3};
        mat *= 5; 
        CHECK(mat == mat*5); //Matrix *= scalar
        mat *= mat1;
        CHECK(mat*mat1 == mat); //Matrix *= Matrix
    }

    //test fot (*)
    for(double i = 0; i < 50; i++){
        vector<double> arr = {0, 0, i, 0, i, 0, i, 0, 0};
        vector<double> arr1 = {0, 0, i, 0, i, 0, i, 0, 0};
        vector<double> arr2 = {0, 0, i*i, 0, i*i, 0, i*i, 0, 0};
        vector<double> arr3 = {0, 0, i*5, 0, i*5, 0, i*5, 0, 0};
        Matrix mat{arr, 3, 3};
        Matrix mat1{arr1, 3, 3};
        Matrix mat2{arr2, 3, 3};
        Matrix mat3{arr3, 3, 3};
        CHECK(mat*mat2 == mat2); //Martix * Matrix
        CHECK(mat1*5 == mat3); //Martix * scalar
        CHECK(5*mat1 == mat3); //scalar * Martix
    }
}

TEST_CASE("check comparisons"){
    for(double i = 0; i < 50; i++){
        vector<double>arr = {i, i, i, i};
        vector<double>arr1 = {i, i, i, i+1};
        vector<double>arr2 = {i, i, i+1, i+1};
        vector<double>arr3 = {i, i, 0, 1};
        Matrix mat {arr, 2, 2};
        Matrix mat1 {arr1, 2, 2};
        Matrix mat2 {arr2, 2, 2};
        Matrix mat3 {arr3, 2, 2};
        CHECK(mat < mat1);
        CHECK(mat1 < mat2);
        CHECK(mat2 >= mat1);
        CHECK(mat1 <= mat2);
        CHECK(mat3 < mat);
        CHECK(mat3 != mat1);
        CHECK_FALSE(mat3 >= mat);
        CHECK_FALSE(mat3 >= mat1);
        CHECK_FALSE(mat3 == mat);
        CHECK_FALSE(mat3 != mat3);
        CHECK_FALSE(mat > mat1);
    }
}

TEST_CASE("check output"){
    vector<double> arr = {1.1, 4.4, 3.3, 5.5};
    Matrix mat {arr, 2, 2};
    CHECK_NOTHROW(cout<< mat <<endl);
}

TEST_CASE("wrong size matrix - input, +, -, * "){
    srand((unsigned) time(0));
	double randomNum1, randomNum2, randomNum3, randomNum4;
	for(double i = 1; i < 50; i++){

		//range of[0,100]
		randomNum1 = (double)(rand() % 100);
		randomNum2 = (double)(rand() % 100);
        randomNum3 = (double)(rand() % 100);
        randomNum4 = (double)(rand() % 100);
		double num1 = randomNum1;
		double num2 = randomNum2;
        double num3 = randomNum3;
        double num4 = randomNum4;

        vector<double> arr = {i, 0, i, 0};
        vector<double> arr1 = {i, 0, i, 0, 1, i, 0, 1, i};
        CHECK_THROWS(Matrix mat(arr, 1, 1));
        CHECK_THROWS(Matrix mat(arr, 0, 6));
        if(num1 != num2){
            CHECK_THROWS(Matrix mat(arr, num1, num2));
        }
        if(num3 != num4){
            CHECK_THROWS(Matrix mat(arr, num3, num4));
        }
        if(num2 != num3){
            Matrix mat(arr, num1, num2);
            Matrix mat1(arr1, num3, num4);
            CHECK_THROWS(mat*mat1);
        }
        if(num1 != num2 || num2 != num3 || num3 != num4){
            Matrix mat(arr, num1, num2);
            Matrix mat1(arr1, num3, num4);
            CHECK_THROWS(mat+mat1);
            CHECK_THROWS(mat-mat1);
        }
    }
}



