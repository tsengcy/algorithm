#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <vector>

namespace sort
{
    bool mergeSort_simple(std::vector<float>& vData);

    template<typename T>
    bool mergeSort(std::vector<T>& vData);

    template<typename T>
    void print(T data);

    
}

#endif //SORT_H_
