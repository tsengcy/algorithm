#include <iostream>
#include <queue>

class mclass
{
public:
    // explicit mclass(int i1)
    // {
    //     std::cout << "initialize with i1" << std::endl;
    // }
    mclass(int i1)
    {
        std::cout << "initialize with i1" << std::endl;
    }
    mclass(const mclass& A)
    {
        std::cout << "copy constructor" << std::endl;
    }
    mclass(int i1, int i2)
    {
        std::cout << "initialize with i2" << std::endl;
    }
};

template<typename OP>
class mclass2
{
public:
    mclass2(){}

    void ope(int a, int b)
    {
        std::cout << OP()(a, b) << std::endl;;
    }
};

int add(int a, int b)
{
    return a + b;
}

struct AddOp {
    int operator()(int a, int b)
    {
        return add(a, b);
    }
};

int main(int argc, char** argv)
{

    std::cout << "------------\n";

    mclass2<AddOp> mc2;

    mc2.ope(1, 2);

    std::priority_queue<int> mpq;



}