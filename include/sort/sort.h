#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <vector>

namespace sort
{
    bool mergeSort(std::vector<float> input, std::vector<float>& output);

    void mergeSortSub(std::vector<float>& vOutput, int nFirst, int nEnd);
}

#endif //SORT_H_
