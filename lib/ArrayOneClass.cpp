
#include "ArrayOneClass.h"

NumberClass ArrayOneClass::operator[](int k) {
    int newSize = size_one_ / size_z_;
    int newPointer = newSize * k;
    NumberClass numberClass(array_main_num_ + newPointer, array_additional_num_, pointer_one_ + newPointer);
    return numberClass;
}
