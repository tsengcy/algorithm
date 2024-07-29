#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <memory>
#include <algorithm>
#include <random>    // for std::default_random_engine
#include <chrono>    // for std::chrono::system_clock

class mA;

using mAptr = std::shared_ptr<mA>;

class mA
{
public:
    mA(std::vector<int> _value)
    {
        value = _value;
    }
    mA()
    {

    }

    void insert(int _value)
    {
        value.push_back(_value);
    }

    void split(std::vector<float> ratio, std::vector<mAptr>& vptr)
    {
        std::cout << "split" << std::endl;
        float tcount=0;
        for(int i=0; i<ratio.size(); i++)
        {
            tcount += ratio.at(i);
        }
        if(tcount != 1)
        {
            std::cout << "wrong size" << std::endl;
            return; 
        }
        std::cout << "a\n";
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        // std::shuffle(value.begin(), value.end(), std::default_random_engine(seed));
        std::cout << "a\n";
        int size = value.size();
        std::cout << size << std::endl;
        int count = 0;
        for(int i=0; i<ratio.size()-1; i++)
        {
            std::cout << "a\n";
            std::vector<int> tmp;
            tmp.assign(value.begin()+count, value.begin()+count+(int)(size*ratio.at(i)));
            count = count + (int)(size*ratio.at(i));
            vptr.push_back(std::make_shared<mA>(tmp));
            std::cout << "b\n";
        }
        std::vector<int> tmp;
        tmp.assign(value.begin()+count, value.end());
        vptr.push_back(std::make_shared<mA>(tmp));
    }
    void print()
    {
        std::cout << "size: " << value.size();
        std::cout << "\nvector:";
        for(int i=0; i<value.size(); i++)
        {
            std::cout << "\t" << value.at(i);
        }
        std::cout << "\n-----------------------\n";
    }
private:
    std::vector<int> value;
};

int main(int argc, char** argv)
{
    std::vector<int> init;
    for(int i=0; i<37; i++)
    {
        init.push_back(i);
    }

    mAptr ptrA = std::make_shared<mA>(init);

    std::vector<float> vratio{0.75, 0.05, 0.2};
    std::vector<mAptr> vAptr;
    ptrA->split(vratio, vAptr);
    for(int i=0; i<vAptr.size(); i++)
    {
        vAptr.at(i)->print();
    }

    ptrA.reset();
}