#include <iostream>
#include <queue>
#include <any>
#include <vector>

enum datatype
{
    BOOL = 0,
    INT = 1,
    FLOAT = 2,
    DOUBLE = 3,
    STRING = 4
};

int main(int argc, char** argv)
{
    std::vector<std::any> vData;
    std::vector<datatype> vDataType;

    vData.push_back(2);
    vDataType.push_back(datatype::INT);

    vData.push_back(true);
    vDataType.push_back(datatype::BOOL);

    vData.push_back("fat guy");
    vDataType.push_back(datatype::STRING);

    std::string str = "slim woman";
    vData.push_back(str);

    for(int i=0; i<vData.size(); i++)
    {
        if(vData.at(i).type() == typeid(std::string))
        {
            std::cout << "string: " << std::any_cast<std::string>(vData.at(i)) << std::endl;
        }
        else if(vData.at(i).type() == typeid(int))
        {
            std::cout << "int: " << std::any_cast<int>(vData.at(i)) << std::endl;
        }
        else if(vData.at(i).type() == typeid(bool))
        {
            std::cout << "bool: " << std::any_cast<bool>(vData.at(i)) << std::endl;
        }
        else if(vData.at(i).type() == typeid(const char*))
        {
            std::cout << "char: " << std::any_cast<const char*>(vData.at(i)) << std::endl;
        }
        else
        {
            std::cout << "other" << std::endl;
        }
    }

}