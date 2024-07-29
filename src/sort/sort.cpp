#include <sort/sort.hpp>
#include <sort/sort_sub.hpp>

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

bool sort::insertionSort_simple(std::vector<float>& vData)
{
    int length = vData.size();
    std::cout << length << std::endl;
    for(int i=1; i<length; i++)
    {
        float curKey = vData.at(i);
        int nReverse = i-1;

        while(nReverse >= 0 && vData.at(nReverse) > curKey)
        {
            vData.at(nReverse+1) = vData.at(nReverse);
            nReverse--;
        }


        vData.at(nReverse+1) = curKey;
#ifdef DEBUG_
        printf("----------------\ni: %d\narray", i);
        for(int i=0; i<length; i++)
            std::cout << "\t" << vData.at(i);
        std::cout << "\n";
#endif

    }
    return true;
}

template<typename T>
bool sort::insertionSort(std::vector<T>& vData)
{
    int length = vData.size();
    for(int i=1; i<length; i++)
    {
        T curKey = vData.at(i);
        int nReverse = i-1;
        while(nReverse >= 0 && vData.at(nReverse) > curKey)
        {
            vData.at(nReverse+1) = vData.at(nReverse);
            nReverse--;
        }
        vData.at(nReverse+1) = curKey;
#ifdef DEBUG_
        printf("----------------\ni: %d\narray", i);
        for(int i=0; i<length; i++)
            std::cout << "\t" << vData.at(i);
        std::cout << "\n";
#endif
    }
    return true;
}

template bool sort::insertionSort<float>(std::vector<float>&);
template bool sort::insertionSort<int>(std::vector<int>&);
template bool sort::insertionSort<double>(std::vector<double>&);
