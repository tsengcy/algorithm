#include <dataframe/dataframe.hpp>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <random> 
#include <chrono> 


std::vector<std::string> vAcceptFileExtension{".txt", ".csv"};

dataframe::dataframe(std::string filename)
{
    // check file
    int length = filename.length();
    std::string strFileExtension = filename.substr(length-5, 4);
    
    if(!strFileExtension.compare(".txt") && !strFileExtension.compare(".csv"))
    {
        throw std::invalid_argument("fail to read " + strFileExtension);
    }
    std::ifstream fin(filename);
    // fin.open(strFileExtension, std::ios::in);
    if(!fin.is_open())
    {
        throw std::invalid_argument("fail to open " + filename);
    }
    std::string str;
    if(!std::getline(fin, str))
    {
        throw std::invalid_argument("no column name");
    }
    std::string token;
    std::stringstream ss(str);
    while(std::getline(ss, token, ','))
    {
        mnCols++;
        mvpFeature.push_back(std::make_shared<feature>(token));
        mvFeatureName.push_back(token);
    }
    // first row
    if(std::getline(fin, str))
    {
        std::string token;
        std::stringstream ss(str);
        std::vector<std::any> vdata;
        int index = 0;
        while(std::getline(ss, token, ','))
        {
            DATATYPE dtype = checkType(token);
            mvpFeature.at(index)->setDataType(dtype);
            if(dtype == DATATYPE::BOOL)
            {
                std::cout << token[1] << std::endl;
                if(token[0] == 'T' || token[0] == 't')
                    vdata.push_back(true);
                else
                    vdata.push_back(false);
            }
            else if(dtype == DATATYPE::DOUBLE)
            {
                vdata.push_back(std::stod(token));
            }
            else
            {
                mvpFeature.at(index)->insertFeature(token);
                vdata.push_back(token);
            }
            index++;
        }
        if(vdata.size() != mnCols)
        {
            throw std::invalid_argument("wrong element number in row " + std::to_string(mnRows));
        }
        mmData.push_back(vdata);
        mnRows++;
    }
    
    while(std::getline(fin, str))
    {    
        std::string token;
        std::stringstream ss(str);
        std::vector<std::any> vdata;
        int index = 0;
        while(std::getline(ss, token, ','))
        {
            DATATYPE dtype = checkType(token);
            if(dtype == DATATYPE::BOOL)
            {
                if(token[0] == 'T' || token[0] == 'T')
                    vdata.push_back(true);
                else
                    vdata.push_back(false);
            }
            else if(dtype == DATATYPE::DOUBLE)
            {
                vdata.push_back(std::stod(token));
            }
            else
            {
                mvpFeature.at(index)->insertFeature(token);
                vdata.push_back(token);
            }
            index++;
        }
        if(vdata.size() != mnCols)
        {
            throw std::invalid_argument("wrong element number in row " + std::to_string(mnRows));
        }
        mmData.push_back(vdata);
        mnRows++;
    }
    fin.close();
}

dataframe::dataframe()
{

}

dataframe::dataframe(dataframePtr dptr, std::vector<std::vector<std::any>> data):mmData(data)
{
    mnRows = mmData.size();
    mnCols = dptr->mnCols;
    mvFeatureName = dptr->mvFeatureName;
    mvpFeature = dptr->mvpFeature;
}

std::vector<std::string> dataframe::getColumns()
{
    std::vector<std::string> vColumns;
    for(auto ft : mvpFeature)
    {
        vColumns.push_back(ft->getFeatureName());
    }
    return vColumns;
}

void dataframe::print()
{
    int widthIndex = std::log10(mnRows) + 2;
    std::cout << std::setw(widthIndex) << "i" << " ";
    for(auto ftptr : mvpFeature)
        std::cout << std::setw(ftptr->getnColumnsWidth()+1) << ftptr->getFeatureName() << " ";
    
    std::cout << std::endl;
    for(int i=0; i<mnRows; i++)
    {
        std::cout << std::setw(widthIndex) << i+1 << " ";
        for(int j=0; j<mnCols; j++)
        {
            // std::cout << j << std::endl;
            if(mvpFeature.at(j)->getFeatureType() == DATATYPE::BOOL)
            {
                if(std::any_cast<bool>(mmData.at(i).at(j)))
                    std::cout << std::setw(mvpFeature.at(j)->getnColumnsWidth()+1) << "True";
                else
                    std::cout << std::setw(mvpFeature.at(j)->getnColumnsWidth()+1) << "False";
            }
            else if(mvpFeature.at(j)->getFeatureType() == DATATYPE::STRING)
            {
                std::cout << std::setw(mvpFeature.at(j)->getnColumnsWidth()+1) << std::any_cast<std::string>(mmData.at(i).at(j));
            }
            else if(mvpFeature.at(j)->getFeatureType() == DATATYPE::DOUBLE)
            {
                std::cout << std::setw(mvpFeature.at(j)->getnColumnsWidth()+1) << std::any_cast<double>(mmData.at(i).at(j));
            }
            std::cout << " ";    
        }
        std::cout <<std::endl;
    }
    std::cout << std::setw(widthIndex) << " " << " ";
    for(int j=0; j<mnCols; j++)
    {
        if(mvpFeature.at(j)->getFeatureType() == DATATYPE::BOOL)
            std::cout << std::setw(mvpFeature.at(j)->getnColumnsWidth()+1) << "BOOL";
        else if(mvpFeature.at(j)->getFeatureType() == DATATYPE::STRING)
            std::cout << std::setw(mvpFeature.at(j)->getnColumnsWidth()+1) << "STRING";
        else if(mvpFeature.at(j)->getFeatureType() == DATATYPE::DOUBLE)
            std::cout << std::setw(mvpFeature.at(j)->getnColumnsWidth()+1) << "DOUBLE";
        std::cout << " ";
    }
    std::cout << std::endl;
}

std::vector<std::any> dataframe::getColData(std::string str)
{
    std::vector<std::any> vstr;
    std::vector<std::string>::iterator it = std::find(mvFeatureName.begin(), mvFeatureName.end(), str);
    if(it != mvFeatureName.end())
    {
        int nCols = std::distance(mvFeatureName.begin(), it);
        for(int i=0; i<mmData.size(); i++)
        {
            vstr.push_back(mmData.at(i).at(nCols));
        }
        return vstr;
    }
    else
    {
        std::cout << "no this data" << std::endl;
        return std::vector<std::any>();
    }
}

featurePtr dataframe::getFeature(std::string str)
{
    std::vector<std::any> vstr;
    std::vector<std::string>::iterator it = std::find(mvFeatureName.begin(), mvFeatureName.end(), str);
    if(it != mvFeatureName.end())
    {
        int nCols = std::distance(mvFeatureName.begin(), it);
        return mvpFeature.at(nCols);
    }
    else
    {
        std::cout << "no this data" << std::endl;
        return featurePtr();
    }
}

void dataframe::splitData(std::vector<float> ratio, std::vector<dataframePtr>& vptr)
{
    float tcount = 0;
    for(float r : ratio)
        tcount += r;
    if(tcount != 1)
    {
        throw std::invalid_argument("ratio error");
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(mmData.begin(), mmData.end(), std::default_random_engine(seed));
    int size = mmData.size();
    int count = 0;
    vptr.resize(ratio.size());
    for(int i=0; i<ratio.size()-1; i++)
    {
        std::vector<std::vector<std::any>> tmp;
        tmp.assign(mmData.begin()+count, mmData.begin()+count+(int)(size*ratio.at(i)));
        count = count + (int)(size*ratio.at(i));
        vptr.at(i) = std::make_shared<dataframe>(shared_from_this(), tmp);
    }
    std::vector<std::vector<std::any>> tmp;
    tmp.assign(mmData.begin()+count, mmData.end());
    vptr.at(ratio.size()-1) = std::make_shared<dataframe>(shared_from_this(), tmp);
}

void dataframe::deleteFeature(std::string strFeature)
{
    std::vector<std::string>::iterator it = std::find(mvFeatureName.begin(), mvFeatureName.end(), strFeature);
    if(it != mvFeatureName.end())
    {
        int nCols = std::distance(mvFeatureName.begin(), it);
        mvpFeature.erase(mvpFeature.begin() + nCols);
        mvFeatureName.erase(mvFeatureName.begin() + nCols);
        for(int i=0; i<mmData.size(); i++)
        {
            mmData.at(i).erase(mmData.at(i).begin() + nCols);
        }
        mnCols--;
    }
    else
    {
        throw std::invalid_argument("wrong feature");
    }
}

void dataframe::insertFeature(featurePtr _ftptr, std::vector<std::any> vdata)
{
    if(mnRows != 0 && mnRows != vdata.size())
    {
        throw std::invalid_argument("insert data's size is wrong");
    }

    if(mnCols == 0)
    {
        mnRows = vdata.size();
        mmData.resize(mnRows);
    }
    mvpFeature.push_back(_ftptr);
    mvFeatureName.push_back(_ftptr->getFeatureName());
    for(int i=0; i<mmData.size(); i++)
    {
        mmData.at(i).push_back(vdata.at(i));
    }

    mnCols++;
}

void dataframe::insertFeature(std::vector<featurePtr> _vftptr, std::vector<std::vector<std::any>> vvdata)
{
    if(_vftptr.size() != vvdata.size())
    {
        throw std::invalid_argument("wrong feature szie");
    }
    for(int i=0; i<_vftptr.size(); i++)
    {
        insertFeature(_vftptr.at(i), vvdata.at(i));
    }
}

dataframePtr dataframe::splitFeature(std::vector<std::string> vstr)
{
    dataframePtr dtptr = std::make_shared<dataframe>();
    std::vector<int> nCols;
    for(int i=0; i<vstr.size(); i++)
    {
        std::vector<std::string>::iterator it = std::find(mvFeatureName.begin(), mvFeatureName.end(), vstr.at(i));
        if(it != mvFeatureName.end())
        {
            nCols.push_back(std::distance(mvFeatureName.begin(), it));
        }
        else
        {
            throw std::invalid_argument("wrong feature");
        }
    }

    std::vector<std::vector<std::any>> vvdata(nCols.size(), std::vector<std::any>(mnRows));
    std::vector<featurePtr> vftptr;
    for(int i=0; i<nCols.size(); i++)
    {
        for(int j=0; j<mnRows; j++)
        {
            vvdata.at(i).at(j) = mmData.at(j).at(nCols.at(i));
        }
        vftptr.push_back(mvpFeature.at(nCols.at(i)));
    }

    dtptr->insertFeature(vftptr, vvdata);

    for(int i=0; i<vstr.size(); i++)
    {
        deleteFeature(vstr.at(i));
    }

    return dtptr;
}



DATATYPE checkType(std::string str)
{
    if(isNumber(str))
    {
        return DATATYPE::DOUBLE;
    }
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    if(lowerStr.compare("true") == 0 || lowerStr.compare("false") == 0)
        return DATATYPE::BOOL;
    else
        return DATATYPE::STRING;
}

bool isNumber(std::string s) {
    std::istringstream iss(s);
    double d;
    char c;
    // Check if the string can be converted to a double and nothing else remains in the stream
    return iss >> d && !(iss >> c);
}