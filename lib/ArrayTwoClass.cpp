
#include "ArrayTwoClass.h"

ArrayOneClass ArrayTwoClass::operator[](int j) {
    int newSize;
    newSize = sizeTwo / size_y_;
    int newPointer;
    newPointer = newSize * j;
    ArrayOneClass arrayOneClass(size_z_, array_main_num_ + newPointer,
                                array_additional_num_, newSize, pointerTwo + newPointer);
    return arrayOneClass;
}
