#include <stdint.h>
#include "NumberClass.h"


class ArrayOneClass {
private:
    int size_z_;
    uint16_t *array_main_num_;
    uint16_t *array_additional_num_;
    int sizeOne;
    int pointerOne;
public:
    ArrayOneClass(int sizeZ, uint16_t *mainDataPtr, uint16_t *supportArray, int sizeOne, int pointerOne) : size_z_(
            sizeZ), array_main_num_(mainDataPtr), array_additional_num_(supportArray), sizeOne(sizeOne), pointerOne(
            pointerOne) {}

    NumberClass operator[] (int k);
};
