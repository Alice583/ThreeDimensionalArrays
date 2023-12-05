#include "NumberClass.h"

void NumberClass::operator=(const int value) {
    SetValue(value);
}

NumberClass::operator int() const {
    int result = 0;
    bool support_num = array_additional_num_[pointerNum / 16] & (1 << pointerAdditional);
    result |= support_num << 0;
    for (int i = 16; i >= 1; --i) {
        support_num = *array_main_num_ & (1 << (i - 1));
        result |= support_num << i;
    }
    return result;
}

void NumberClass::SetValue(int value){
    *array_main_num_ = 0;
    int num = value;
    bool support_num;
    support_num = num % 2;
    array_additional_num_[pointerNum / 16] |= (support_num << pointerAdditional);
    num /= 2;
    int count = 0;
    while (num != 0) {
        support_num = num % 2;
        *array_main_num_ |= (support_num << count);
        count++;
        num /= 2;
    }
}


std::istream &operator>>(std::istream& stream, NumberClass numberClass) {
    int buf;
    stream >> buf;
    numberClass.SetValue(buf);
    return stream;
}
