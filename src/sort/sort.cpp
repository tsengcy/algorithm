#include <sort/sort.h>
#include <sort/sort_sub.h>

bool sort::mergeSort(std::vector<float> input, std::vector<float>& output)
{
    output = input;

    mergeSortSub(output, 0, output.size() - 1);

    return true;
}