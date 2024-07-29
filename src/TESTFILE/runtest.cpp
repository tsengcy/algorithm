#include <iostream>
#include <gtest/gtest.h>
#include <sort/sort.hpp>

TEST(TestMergerSort, mergeSort)
{
    //Arrange
    std::vector<float> inputVector{9.0f, 5.0f, 7.0f, -1.7f, -2.9f};

    sort::mergeSort_simple(inputVector);

    std::vector<float> ansVector{-2.9f, -1.7f, 5.0f, 7.0f, 9.0f};
    //Assert
    ASSERT_EQ(ansVector, inputVector);
}

TEST(TestMergerSort, mergeSortInt)
{
    //Arrange
    std::vector<int> inputVector{9, 5, 7, -1, -2, -1};

    sort::mergeSort(inputVector);

    std::vector<int> ansVector{-2, -1, -1, 5, 7, 9};
    //Assert
    ASSERT_EQ(ansVector, inputVector);
}

TEST(TestMergerSort, mergeSortDouble)
{
    //Arrange
    std::vector<double> inputVector{9.0, 5.0, 7.0, -1.7, -2.9, 5.0};

    sort::mergeSort<double>(inputVector);

    std::vector<double> ansVector{-2.9, -1.7, 5.0, 5.0, 7.0, 9.0};
    //Assert
    ASSERT_EQ(ansVector, inputVector);
}

TEST(TestInsertionSort, InsertionSort)
{
    //Arrange
    std::vector<float> inputVector{9.0f, 5.0f, 7.0f, -1.7f, -2.9f, 5.0f};

    sort::insertionSort_simple(inputVector);

    std::vector<float> ansVector{-2.9f, -1.7f, 5.0f, 5.0f, 7.0f, 9.0f};
    //Assert
    ASSERT_EQ(ansVector, inputVector);
}

TEST(TestInsertionSort, InsertionSortDouble)
{
    //Arrange
    std::vector<double> inputVector{9.0, 5.0, 7.0, -1.7, -2.9, 5.0};

    sort::insertionSort<double>(inputVector);

    std::vector<double> ansVector{-2.9, -1.7, 5.0, 5.0, 7.0, 9.0};
    //Assert
    ASSERT_EQ(ansVector, inputVector);
}

int main(int argc, char **argv)
{
    // sort::print(10.0f);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}