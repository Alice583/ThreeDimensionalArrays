#include <stdint.h>
#include <iostream>
#include "ArrayTwoClass.h"

class ArrayThreeClass {
private:
//    int* arr;
    int size_x_;
    int size_y_;
    int size_z_;
    uint16_t* array_main_num_ ;
    uint16_t* array_additional_num_;
    int pointerThree = 0;
    int sizeThree;
public:
    ArrayThreeClass(int sizeX, int sizeY, int sizeZ) : size_x_(sizeX), size_y_(sizeY), size_z_(sizeZ) {
        array_main_num_ = new uint16_t[sizeX * sizeY * sizeZ];
        array_additional_num_ = new uint16_t[(sizeX * sizeY * sizeZ - 1) / 16 + 1];
        sizeThree = sizeX * sizeY * sizeZ;
        for (int i = 0; i < sizeThree; ++i) {
            array_main_num_[i] = 0;
        }
        for (int i = 0; i < (sizeThree - 1) / 16 + 1; ++i) {
            array_additional_num_[i] = 0;
        }
    }

    ~ArrayThreeClass() {
        delete[] array_main_num_;
        delete[] array_additional_num_;
    }

    ArrayTwoClass operator[] (int i);

    int GetNum(int indexMain) const;

    void WriteNum(int val, int indexMain);

    static ArrayThreeClass MakeArray(int x, int y, int z);

    friend ArrayThreeClass operator+(const ArrayThreeClass& arrayThreeClass1, const ArrayThreeClass& arrayThreeClass2);

    friend ArrayThreeClass operator-(const ArrayThreeClass& arrayThreeClass1, const ArrayThreeClass& arrayThreeClass2);

    friend ArrayThreeClass operator*(int multiplier, const ArrayThreeClass& arrayThreeClass2);

    friend ArrayThreeClass operator*(const ArrayThreeClass& arrayThreeClass2, int multiplier);

    friend std::ostream& operator<<(std::ostream& stream, const ArrayThreeClass& arrayThreeClass);
};
