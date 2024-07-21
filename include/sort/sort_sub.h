#ifndef SORT_SUB_H_
#define SORT_SUB_H_

#include <iostream>
#include <vector>

void mergeSortSub(std::vector<float>& vOutput, int nFirst, int nEnd);

template<typename T>
void mergeSortSub(std::vector<T>& vOutput, int nFirst, int nEnd);

#endif // SORT_SUB_H_