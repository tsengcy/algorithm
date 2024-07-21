#include <sort/sort_sub.h>
#include <iomanip>

void mergeSortSub(std::vector<float>& vOutput, int nFirst, int nEnd)
{
    if(nFirst == nEnd)
        return;
    
    int nCenter = (nFirst + nEnd) / 2;
    
    mergeSortSub(vOutput, nFirst, nCenter);
    mergeSortSub(vOutput, nCenter+1, nEnd);

    std::vector<float> vLeft(vOutput.begin() + nFirst, vOutput.begin() + nCenter+1);
    std::vector<float> vRight(vOutput.begin() + nCenter+1, vOutput.begin() + nEnd+1);

#ifdef DEBUG_
    printf("-------------------\nnFirst: %d\tnCenter: %d\tEnd: %d\nLeft: ", nFirst, nCenter, nEnd);
    for(int i=0; i<vLeft.size(); i++)
        printf("\t%.3f", vLeft.at(i));
    printf("\nRight: ");
    for(int i=0; i<vRight.size(); i++)
        printf("\t%.3f", vRight.at(i));
    printf("\n");
#endif

    int nLeft = 0;
    int nRight = 0;

    int nCount = nFirst;

    while(nLeft < vLeft.size() && nRight < vRight.size())
    {
        if(vLeft.at(nLeft) < vRight.at(nRight))
        {
            vOutput.at(nCount) = vLeft.at(nLeft);
            nLeft++;
            nCount++;
        }
        else
        {
            vOutput.at(nCount) = vRight.at(nRight);
            nRight++;
            nCount++;
        }
    }

    if(nLeft == vLeft.size())
    {
        while (nRight < vRight.size())
        {
            vOutput.at(nCount) = vRight.at(nRight);
            nRight++;
            nCount++;
        }
        
    }
    else if(nRight == vRight.size())
    {
        while (nLeft < vLeft.size())
        {
            vOutput.at(nCount) = vLeft.at(nLeft);
            nLeft++;
            nCount++;
        }
    }

#ifdef DEBUG_
    printf("Merge: ");
    for(int i=nFirst; i<=nEnd; i++)
        printf("\t%.3f", vOutput.at(i));
    printf("\n");
#endif
}

template<typename T>
void mergeSortSub(std::vector<T>& vOutput, int nFirst, int nEnd)
{
    if(nFirst == nEnd)
        return;
    
    int nCenter = (nFirst + nEnd) / 2;
    
    mergeSortSub(vOutput, nFirst, nCenter);
    mergeSortSub(vOutput, nCenter+1, nEnd);

    std::vector<T> vLeft(vOutput.begin() + nFirst, vOutput.begin() + nCenter+1);
    std::vector<T> vRight(vOutput.begin() + nCenter+1, vOutput.begin() + nEnd+1);

#ifdef DEBUG_
    printf("-------------------\nnFirst: %d\tnCenter: %d\tEnd: %d\nLeft: ", nFirst, nCenter, nEnd);
    for(int i=0; i<vLeft.size(); i++)
        std::cout << "\t" << std::setprecision(3) << vLeft.at(i);
    printf("\nRight: ");
    for(int i=0; i<vRight.size(); i++)
        std::cout << "\t" << std::setprecision(3) << vRight.at(i);
    printf("\n");
#endif
    int nLeft = 0;
    int nRight = 0;
    int nCount = nFirst;

    while(nLeft < vLeft.size() && nRight < vRight.size())
    {
        if(vLeft.at(nLeft) < vRight.at(nRight))
            vOutput.at(nCount++) = vLeft.at(nLeft++);
        else
            vOutput.at(nCount++) = vRight.at(nRight++);
    }

    if(nLeft == vLeft.size())
        while (nRight < vRight.size())
            vOutput.at(nCount++) = vRight.at(nRight++);
    else if(nRight == vRight.size())
        while (nLeft < vLeft.size())
            vOutput.at(nCount++) = vLeft.at(nLeft++);

#ifdef DEBUG_
    printf("Merge: ");
    for(int i=nFirst; i<=nEnd; i++)
        std::cout << "\t" << std::setprecision(3) << vOutput.at(i);
    printf("\n");
#endif

}

template void mergeSortSub<float>(std::vector<float>&, int, int);
template void mergeSortSub<double>(std::vector<double>&, int, int);
template void mergeSortSub<int>(std::vector<int>&, int, int);