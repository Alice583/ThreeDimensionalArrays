//#include <C:\Users\Alice\labwork5-Alice583\lib>
//#include "lib\ArrayThreeClass.h"
#include <iostream>
#include "ArrayThreeClass.h"
int main(int argc, char **argv) {
//    int x = 2;
//    int y = 5;
//    int z = 7;
//    ArrayThreeClass arr = ArrayThreeClass::MakeArray(x, y, z);
//    arr[0][0][0] = 1;
//    arr[0][2][1] = 5;
//    arr[1][4][6] = 7;
//
//    for (int i = 0; i < x; ++i) {
//        for (int j = 0; j < y; ++j) {
//            for (int k = 0; k < z; ++k) {
//                std::cout << arr[i][j][k] << ' ';
//            }
//            std::cout << '\n';
//        }
//        std::cout << '\n';
//    }
//    int* arr = new int[4];
//    arr[0] = 0;
//    arr[1] = 1;
//    arr[1] = 12;
//    std::cout << arr[1];
//    int x = 2;
//    int y = 5;
//    int z = 7;
//    ArrayThreeClass arr = ArrayThreeClass::MakeArray(x, y, z);
//    arr[0][0][0] = 1;
//    arr[0][2][1] = 5;
//    arr[1][4][6] = 7;
//
//    for (int i = 0; i < x; ++i) {
//        for (int j = 0; j < y; ++j) {
//            for (int k = 0; k < z; ++k) {
//                std::cout << arr[i][j][k] << ' ';
//            }
//            std::cout << '\n';
//        }
//        std::cout << '\n';
//    }


    ArrayThreeClass arrayThreeClass1 = ArrayThreeClass::MakeArray(2, 2, 2);
    std::cin >> arrayThreeClass1[0][0][0];
    arrayThreeClass1[0][0][1] = 2;
    arrayThreeClass1[0][1][0] = 3;
    arrayThreeClass1[0][1][1] = 4;
    arrayThreeClass1[1][0][0] = 5;
    arrayThreeClass1[1][0][1] = 6;
    arrayThreeClass1[1][1][0] = 7;
    arrayThreeClass1[1][1][1] = 8;
//    std::cout << arrayThreeClass1;
    ArrayThreeClass arrayThreeClass2 = ArrayThreeClass::MakeArray(2, 2, 2);
    arrayThreeClass2[0][0][1] = 2;
    arrayThreeClass2[0][1][0] = 3;
    arrayThreeClass2[0][1][1] = 4;
    arrayThreeClass2[1][0][0] = 5;
    arrayThreeClass2[1][0][1] = 6;
    arrayThreeClass2[1][1][0] = 7;
    arrayThreeClass2[1][1][1] = 8;
    ArrayThreeClass arrayThreeClass3 = arrayThreeClass1 + arrayThreeClass2;
    std::cout << arrayThreeClass3;
//    arrayThreeClass1[1][1][1] = 13;
//    ArrayThreeClass arrayThreeClass2 = ArrayThreeClass::MakeArray(2, 2, 2);
//    arrayThreeClass2[1][1][1] = 2;
//    ArrayThreeClass arrayThreeClass3 = arrayThreeClass1 + arrayThreeClass2;
    return 0;
}