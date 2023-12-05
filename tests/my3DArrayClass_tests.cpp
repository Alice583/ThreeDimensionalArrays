#include "lib/ArrayThreeClass.h"
#include <gtest/gtest.h>


TEST(ArrayThreeClassTest, NullTest) {
    auto arr = ArrayThreeClass::MakeArray(7, 4, 10);
    ASSERT_EQ(arr[0][0][0], 0);
    ASSERT_EQ(arr[6][2][0], 0);
    ASSERT_EQ(arr[0][0][9], 0);
}

TEST(ArrayThreeClassTest, AssignmentTest) {
    auto arr = ArrayThreeClass::MakeArray(7, 4, 10);
    arr[1][1][1] = 10;
    arr[2][3][9] = 1;
    int num1 = arr[1][1][1];
    int num2 = arr[2][3][9];
    ASSERT_EQ(num1, 10);
    ASSERT_EQ(num2, 1);
    ASSERT_EQ(arr[0][0][0], 0);
}

TEST(ArrayThreeClassTest, SumMatrixTest) {
    auto arr1 = ArrayThreeClass::MakeArray(2, 2, 2);
    arr1[0][0][0] = 1;
    arr1[0][0][1] = 2;
    arr1[0][1][0] = 3;
    arr1[0][1][1] = 4;
    arr1[1][0][0] = 5;
    arr1[1][0][1] = 6;
    arr1[1][1][0] = 7;
    arr1[1][1][1] = 8;

    auto arr2 = ArrayThreeClass::MakeArray(2, 2, 2);
    arr2[0][0][0] = 8;
    arr2[0][0][1] = 7;
    arr2[0][1][0] = 6;
    arr2[0][1][1] = 5;
    arr2[1][0][0] = 4;
    arr2[1][0][1] = 3;
    arr2[1][1][0] = 2;
    arr2[1][1][1] = 1;

    auto arr3 = arr1 + arr2;

    ASSERT_EQ(arr3[0][0][0], 9);
    ASSERT_EQ(arr3[0][0][1], 9);
    ASSERT_EQ(arr3[0][1][0], 9);
    ASSERT_EQ(arr3[0][1][1], 9);
    ASSERT_EQ(arr3[1][0][0], 9);
    ASSERT_EQ(arr3[1][0][1], 9);
    ASSERT_EQ(arr3[1][1][0], 9);
    ASSERT_EQ(arr3[1][1][1], 9);
}

TEST(ArrayThreeClassTest, MinMatrixTest) {
    auto arr1 = ArrayThreeClass::MakeArray(2, 2, 2);
    arr1[0][0][0] = 10;
    arr1[0][0][1] = 20;
    arr1[0][1][0] = 30;
    arr1[0][1][1] = 40;
    arr1[1][0][0] = 50;
    arr1[1][0][1] = 60;
    arr1[1][1][0] = 70;
    arr1[1][1][1] = 80;

    auto arr2 = ArrayThreeClass::MakeArray(2, 2, 2);
    arr2[0][0][0] = 8;
    arr2[0][0][1] = 7;
    arr2[0][1][0] = 6;
    arr2[0][1][1] = 5;
    arr2[1][0][0] = 4;
    arr2[1][0][1] = 3;
    arr2[1][1][0] = 2;
    arr2[1][1][1] = 1;

    auto arr3 = arr1 - arr2;

    ASSERT_EQ(arr3[0][0][0], 2);
    ASSERT_EQ(arr3[0][0][1], 13);
    ASSERT_EQ(arr3[0][1][0], 24);
    ASSERT_EQ(arr3[0][1][1], 35);
    ASSERT_EQ(arr3[1][0][0], 46);
    ASSERT_EQ(arr3[1][0][1], 57);
    ASSERT_EQ(arr3[1][1][0], 68);
    ASSERT_EQ(arr3[1][1][1], 79);
}

TEST(ArrayThreeClassTest, MultNumOnMatrixTest) {
    auto arr1 = ArrayThreeClass::MakeArray(2, 2, 2);
    arr1[0][0][0] = 10;
    arr1[0][0][1] = 20;
    arr1[0][1][0] = 30;
    arr1[0][1][1] = 40;
    arr1[1][0][0] = 50;
    arr1[1][0][1] = 60;
    arr1[1][1][0] = 70;
    arr1[1][1][1] = 80;

    auto arr3 = 10 * arr1;

    ASSERT_EQ(arr3[0][0][0], 100);
    ASSERT_EQ(arr3[0][0][1], 200);
    ASSERT_EQ(arr3[0][1][0], 300);
    ASSERT_EQ(arr3[0][1][1], 400);
    ASSERT_EQ(arr3[1][0][0], 500);
    ASSERT_EQ(arr3[1][0][1], 600);
    ASSERT_EQ(arr3[1][1][0], 700);
    ASSERT_EQ(arr3[1][1][1], 800);
}

TEST(ArrayThreeClassTest, MultMatrixOnNumTest) {
    auto arr1 = ArrayThreeClass::MakeArray(2, 2, 2);
    arr1[0][0][0] = 10;
    arr1[0][0][1] = 20;
    arr1[0][1][0] = 30;
    arr1[0][1][1] = 40;
    arr1[1][0][0] = 50;
    arr1[1][0][1] = 60;
    arr1[1][1][0] = 70;
    arr1[1][1][1] = 80;

    auto arr3 = arr1 * 2;

    ASSERT_EQ(arr3[0][0][0], 20);
    ASSERT_EQ(arr3[0][0][1], 40);
    ASSERT_EQ(arr3[0][1][0], 60);
    ASSERT_EQ(arr3[0][1][1], 80);
    ASSERT_EQ(arr3[1][0][0], 100);
    ASSERT_EQ(arr3[1][0][1], 120);
    ASSERT_EQ(arr3[1][1][0], 140);
    ASSERT_EQ(arr3[1][1][1], 160);
}

TEST(Array3dTestSuite, InTest) {
    auto arr = ArrayThreeClass::MakeArray(12, 13, 14);

    std::stringstream stream;
    stream << 89;
    stream >> arr[10][12][13];

    ASSERT_EQ(arr[10][12][13], 89);
}

TEST(Array3dTestSuite, OutTest) {
    auto arr = ArrayThreeClass::MakeArray(5, 5, 13);

    arr[1][0][12] = 1300;

    std::stringstream stream;
    stream << arr[1][0][12];

    ASSERT_EQ(stream.str(), "1300");
}

TEST(ArrayThreeClassTest, NumInArrTest) {
    auto arr1 = ArrayThreeClass::MakeArray(2, 2, 2);
    arr1[0][0][0] = 1000;
    arr1[0][0][1] = 2345;

    ASSERT_EQ(arr1[0][0][0], 1000);
    ASSERT_EQ(arr1[0][0][1], 2345);
}
