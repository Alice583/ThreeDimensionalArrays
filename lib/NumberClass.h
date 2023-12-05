#include <stdint.h>
#include <iostream>

//#ifndef LABWORK5_ALICE583_NUMBERCLASS_H
//#define LABWORK5_ALICE583_NUMBERCLASS_H


class NumberClass {
private:
    uint16_t *array_main_num_;
    uint16_t *array_additional_num_;
    int pointerNum;
    int pointerAdditional;
public:
    NumberClass(uint16_t *mainDataPtr, uint16_t *supportArray, int pointerNum) : array_main_num_(mainDataPtr),
                                                                                 array_additional_num_(supportArray), pointerNum(pointerNum) {
//        array_additional_num_ = &supportArray[pointerNum / 16];
        pointerAdditional = pointerNum % 16;
    }
    void operator=(const int value);

    operator int() const;

    void SetValue(int value) const;

    friend std::istream& operator>>(std::istream& stream, const NumberClass& numberClass);
};


//#endif //LABWORK5_ALICE583_NUMBERCLASS_H
