#include <iostream>
#include <heap/heap.hpp>

int main(int argc, char **argv)
{
    Heap<int> hp;
    std::vector<int> vdata{0,2,5,1,7};
    for(int i=0; i<vdata.size(); i++)
    {
        hp.push(vdata.at(i));
    }

    std::cout << "heap:";
    while(hp.size()!=0)
    {
        std::cout << "\t" << hp.top();
        hp.pop();
    }
    std::cout << std::endl;

    return 0;
}