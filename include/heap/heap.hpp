#ifndef HEAP_HPP_
#define HEAP_HPP_

#include <functional>
#include <memory>
#include <iostream>
#include <vector>
#include <math.h>

template<typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename _variableName, typename _Compare = std::less<_variableName>>
class Heap;

template<typename _variableName, typename _Compare>
class Heap
{
public:
    /** \brief constructor of  Heap*/
    Heap(){};

    _variableName top()
    {
        return vData.at(0);
    }

    void push(_variableName data)
    {
        vData.push_back(data);
        int index = vData.size() - 1;
        while((index-1)/2 >= 0)
        {
            if(vData.at(index) < vData.at((index-1)/2))
            {
                swap(vData.at(index), vData.at((index-1)/2));
                index = (index-1)/2;
            }
            else
                break;
        }
    }

    void pop()
    {
        swap(vData.at(0), vData.back());
        vData.pop_back();
        heapify();
    }

    int size()
    {return vData.size(); }

    // void Decrease();

    // void Remove();

    void Union(Heap<_variableName, _Compare> hp)
    {
        while(hp.size()!=0)
        {
            _variableName tmp;
            tmp = hp.top();
            hp.pop();

            push(tmp);
        }
    }

    void heapify(){heapifySub(0);};

    void heapifySub(int index)
    {
        if(2*index + 2 < vData.size())
        {
            if(_Compare()(vData.at(2*index+1), vData.at(2*index+2)))
            {
                if(_Compare()(vData.at(2*index+1), vData.at(index)))
                {
                    swap(vData.at(index), vData.at(2*index +1));
                    heapifySub(2*index+1);
                }
            }
            else
            {
                if(_Compare()(vData.at(2*index+2), vData.at(index)))
                {
                    swap(vData.at(index), vData.at(2*index+2));
                    heapifySub(2*index+2);
                }
            }
        }
        else if(2 * index + 1 < vData.size())
        {
            if(_Compare()(vData.at(2*index+1), vData.at(index)))
            {
                swap(vData.at(index), vData.at(2*index +1));
                heapifySub(2*index+1);
            }
        }
        else
        {
            return;
        }
    }

private:
    std::vector<_variableName> vData;
};

#endif // HEAP_HPP_

