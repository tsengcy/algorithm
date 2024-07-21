#include <iostream>
#include <gtest/gtest.h>
#include <sort/sort.h>

TEST(TestMergerSort, mergeSort)
{
    //Arrange
    std::vector<float> inputVector{9.0f, 5.0f, 7.0f, -1.7f, -2.9f};

    //Act
    std::vector<float> outputVector;

    sort::mergeSort(inputVector, outputVector);

    std::vector<float> ansVector{-2.9f, -1.7f, 5.0f, 7.0f, 9.0f};
    //Assert
    ASSERT_EQ(ansVector, outputVector);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}