#include <sort/sort.h>

bool sort::mergeSort(std::vector<float> input, std::vector<float>& output)
{

}

void sort::mergeSortSub(std::vector<float>& vOutput, int nFirst, int nEnd)
{
    if(nFirst == nEnd)
        return;
    
    int nCenter = (nFirst + nEnd) / 2;
    
    mergeSortSub(vOutput, nFirst, nCenter);
    mergeSortSub(vOutput, nCenter+1, nEnd);

    
}