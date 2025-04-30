#include "ArrayTwoClass.h"

ArrayOneClass ArrayTwoClass::operator[](int j) {
    int newSize;
    newSize = size_two_ / size_y_;
    int newPointer;
    newPointer = newSize * j;
    ArrayOneClass arrayOneClass(size_z_, array_main_num_ + newPointer,
                                array_additional_num_, newSize, pointer_two_ + newPointer);
    return arrayOneClass;
}
