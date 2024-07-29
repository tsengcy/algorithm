#include <fstream>
#include <iostream>
#include <map>


int main(int argc, char** argv)
{
    std::map<std::string, int> maps;
    maps.insert(std::pair<std::string ,int>("a", 1));
    maps.insert(std::pair<std::string ,int>("b", 1));
    maps.insert(std::pair<std::string ,int>("a", 2));

    std::cout << "a: " << maps.count("a") << std::endl;
    std::cout << "b: " << maps.count("b") << std::endl;
    std::cout << "c: " << maps.count("c") << std::endl;

    std::cout << "size: " << maps.size() << std::endl;

    for(const auto& ma : maps)
    {
        std::cout << ma.first << "\t" << ma.second << std::endl;
    }

    maps.erase("a");
    std::cout << "size: " << maps.size() << std::endl;
    for(const auto& ma : maps)
    {
        std::cout << ma.first << "\t" << ma.second << std::endl;
    }

}