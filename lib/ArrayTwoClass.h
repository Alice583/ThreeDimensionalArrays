#include <stdint.h>
#include "ArrayOneClass.h"

class ArrayTwoClass {
private:
    int size_y_;
    int size_z_;
    uint16_t *array_main_num_;
    uint16_t *array_additional_num_;
    int sizeTwo;
    int pointerTwo;
public:
    ArrayTwoClass(int sizeY, int sizeZ, uint16_t *mainDataPtr, uint16_t *supportArray, int size, int pointer) : size_y_(
            sizeY), size_z_(sizeZ), array_main_num_(mainDataPtr), array_additional_num_(supportArray), sizeTwo(size),
            pointerTwo(pointer) {
            size_y_ = sizeY;
            sizeTwo = size;
        }

    ArrayOneClass operator[] (int j);
};