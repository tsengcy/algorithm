#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <vector>

namespace sort
{
    bool mergeSort_simple(std::vector<float>& vData);

    template<typename T>
    bool mergeSort(std::vector<T>& vData);

    bool insertionSort_simple(std::vector<float>& vData);

    template<typename T>
    bool insertionSort(std::vector<T>& vData);
}   

#endif //SORT_H_
