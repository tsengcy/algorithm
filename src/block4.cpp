#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


int main(int argc, char** argv)
{
    std::vector<int> v{1,5,3,3,1,2};

    std::sort(v.begin(), v.end());

    std::cout << "vector: ";
    for(int i=0; i<v.size(); i++)
    {
        std::cout << "\t" << v.at(i);
    }
    std::cout << std::endl;


    std::cout << "vector: ";
    for(int i=0; i<v.size(); i++)
    {
        std::cout << "\t" << v.at(i);
    }
    std::cout << std::endl;

}