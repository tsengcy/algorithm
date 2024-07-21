#include <sort/sort.h>
#include <sort/sort_sub.h>

bool sort::mergeSort_simple(std::vector<float>& vData)
{
    mergeSortSub(vData, 0, vData.size() - 1);
    return true;
}

template<typename T>
bool sort::mergeSort(std::vector<T>& vData)
{
    mergeSortSub<T>(vData, 0, vData.size()-1);
    return true;
}

template bool sort::mergeSort<float>(std::vector<float>&);
template bool sort::mergeSort<int>(std::vector<int>&);
template bool sort::mergeSort<double>(std::vector<double>&);

template<typename T>
void sort::print(T data)
{
    std::cout << data << std::endl;
}

template void sort::print<float>(float);

