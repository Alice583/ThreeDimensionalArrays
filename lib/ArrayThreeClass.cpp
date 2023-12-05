#include "ArrayThreeClass.h"
#include <iostream>

ArrayTwoClass ArrayThreeClass::operator[](int i) {
    int newSize = size_three_ / size_x_;
    int newPointer = newSize * i;
    ArrayTwoClass arrayTwoClass(size_y_, size_z_, array_main_num_ + newPointer,
                                array_additional_num_, newSize, pointer_three_ + newPointer);
    return arrayTwoClass;
}

ArrayThreeClass ArrayThreeClass::MakeArray(int x, int y, int z) {
    ArrayThreeClass arrayThreeClass(x, y, z);
    return arrayThreeClass;
}

int ArrayThreeClass::GetNum(int indexMain) const {
    int result = 0;
    int indexSupport = indexMain % 16;
    bool support_num = array_additional_num_[indexMain / 16] & (1 << indexSupport);
    result |= support_num << 0;
    for (int i = 16; i >= 1; --i) {
        support_num = array_main_num_[indexMain] & (1 << (i - 1));
        result |= support_num << i;
    }
    return result;
}

void ArrayThreeClass::WriteNum(int val, int indexMain) {
    array_main_num_[indexMain] = 0;
    int num = val;
    bool support_num;
    support_num = num % 2;
    int indexSupport = indexMain % 16;
    array_additional_num_[indexMain / 16] |= (support_num << indexSupport);
    num /= 2;
    int count = 0;
    while (num != 0) {
        support_num = num % 2;
        array_main_num_[indexMain] |= (support_num << count);
        count++;
        num /= 2;
    }
}

ArrayThreeClass operator+(const ArrayThreeClass& arrayThreeClass1, const ArrayThreeClass& arrayThreeClass2) {
    ArrayThreeClass result = ArrayThreeClass::MakeArray(arrayThreeClass1.size_x_, arrayThreeClass1.size_y_, arrayThreeClass1.size_z_);
    for (int i = 0; i < arrayThreeClass1.size_three_; ++i) {
        result.WriteNum(arrayThreeClass1.GetNum(i) + arrayThreeClass2.GetNum(i), i);
    }
    return result;
}

ArrayThreeClass operator-(const ArrayThreeClass& arrayThreeClass1, const ArrayThreeClass& arrayThreeClass2) {
    ArrayThreeClass result = ArrayThreeClass::MakeArray(arrayThreeClass1.size_x_, arrayThreeClass1.size_y_, arrayThreeClass1.size_z_);
    for (int i = 0; i < arrayThreeClass1.size_three_; ++i) {
        result.WriteNum(arrayThreeClass1.GetNum(i) - arrayThreeClass2.GetNum(i), i);
    }
    return result;
}

ArrayThreeClass operator*(int multiplier, const ArrayThreeClass& arrayThreeClass2) {
    ArrayThreeClass result = ArrayThreeClass::MakeArray(arrayThreeClass2.size_x_, arrayThreeClass2.size_y_, arrayThreeClass2.size_z_);
    for (int i = 0; i < arrayThreeClass2.size_three_; ++i) {
        result.WriteNum(multiplier * arrayThreeClass2.GetNum(i), i);
    }
    return result;
}

ArrayThreeClass operator*(const ArrayThreeClass& arrayThreeClass2, int multiplier) {
    ArrayThreeClass result = ArrayThreeClass::MakeArray(arrayThreeClass2.size_x_, arrayThreeClass2.size_y_, arrayThreeClass2.size_z_);
    for (int i = 0; i < arrayThreeClass2.size_three_; ++i) {
        result.WriteNum(arrayThreeClass2.GetNum(i) * multiplier, i);
    }
    return result;
}

std::ostream &operator<<(std::ostream& stream, const ArrayThreeClass& arrayThreeClass) {
    int indexNumArray = 0;
    stream << '[';
    stream << '\n';
    for (int i = 0; i < arrayThreeClass.size_x_; ++i) {
        stream << '[';
        for (int j = 0; j < arrayThreeClass.size_y_; ++j) {
            stream << '[';
            for (int k = 0; k < arrayThreeClass.size_z_; ++k) {
                stream << arrayThreeClass.GetNum(indexNumArray++);
                if (k != arrayThreeClass.size_z_ - 1) {
                    stream << ';';
                    stream << ' ';
                }
            }
            stream << ']';
        }
        stream << ']';
        stream << '\n';
    }
    stream << ']';
    return stream;
}
