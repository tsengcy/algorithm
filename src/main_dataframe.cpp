#include <dataframe/dataframe.hpp>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cerr << "wrong input size" << std::endl;
        return -1;
    }

    dataframePtr df = std::make_shared<dataframe>(argv[1]);

    std::vector<std::string> vcolumns = df->getColumns();
    
    for(int i=0; i<vcolumns.size(); i++)
    {
        std::cout << vcolumns.at(i) << "\t";
    }
    std::cout << "\n";

    std::cout << "----" << std::endl;
    df->print();
    std::cout << "=====\n";
    featurePtr pft = df->getFeature("name");
    pft->print();
    std::cout << "=====\n";
    df->getColData("age");
    std::cout << "=====divide data =======\n";
    std::vector<dataframePtr> vdfptr;
    std::vector<float> ratio{0.8, 0.2};
    df->splitData(ratio, vdfptr);

    for(int i=0; i<vdfptr.size(); i++)
    {
        vdfptr.at(i)->print();
        std::cout << "---------\n";
    }
    std::cout << "-----delete element----\n";
    df->deleteFeature("age");
    df->print();

    std::cout << "-------split--------\n";
    std::vector<std::string> vstr{"weight"};
    dataframePtr ddptr = df->splitFeature(vstr);
    ddptr->print();
    std::cout << "--\n";
    df->print();

}