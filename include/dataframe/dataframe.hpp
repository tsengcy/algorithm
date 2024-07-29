#ifndef DATAFRAME_HPP_
#define DATAFRAME_HPP_

#include <iostream>
#include <vector>
#include <any>
#include <set>
#include <memory>
#include <map>



enum DATATYPE
{
    BOOL = 0,
    DOUBLE = 1,
    STRING = 2
};

class feature;
using featurePtr = std::shared_ptr<feature>;


class feature
{
public:
    feature(std::string _strFeatureName):strFeatureName(_strFeatureName)
    {
        nColumnWidth = _strFeatureName.length();
    };

    void setDataType(DATATYPE _dtFeatureType)
    {
        dtDataType = _dtFeatureType;
        if(dtDataType == DATATYPE::BOOL)
        {
            if(nColumnWidth < 5){nColumnWidth=5;}
        }
        else if(dtDataType == DATATYPE::DOUBLE)
        {
            if(nColumnWidth < 10){nColumnWidth=10;}
        }
        else if(dtDataType == DATATYPE::STRING)
        {
            if(nColumnWidth < 5){nColumnWidth=7;}
        }
    };

    void insertFeature(std::string strFeature)
    {
        if(mapFeature.count(strFeature) == 1)
        {
            mapFeature[strFeature]++;
        }
        else
        {
            mapFeature.insert(std::pair(strFeature, 1));
            if(nColumnWidth < strFeature.length())
                nColumnWidth = strFeature.length();
        }
    }

    int getNumberOfFeature(){return mapFeature.size();}

    std::vector<std::string> getFeature()
    {
        std::vector<std::string> vFeature;
        for(auto s : mapFeature) 
        {
            vFeature.push_back(s.first);
        }
        return vFeature;
    };

    std::vector<std::pair<std::string, int>> analysisFeature()
    {
        std::vector<std::pair<std::string, int>> vPair;
        for(auto s : mapFeature) 
        {
            vPair.push_back(s);
        }
        return vPair;
    }

    DATATYPE getFeatureType(){return dtDataType;};

    std::string getFeatureName(){return strFeatureName;}

    int getnColumnsWidth(){return nColumnWidth;}

    void print()
    {
        std::cout << "Feature: " << strFeatureName << "\n";
        if(dtDataType == DATATYPE::STRING)
        {
            std::cout << "type:\t STRING\nMember: ";
            for(auto a : mapFeature)
                std::cout << " " << a.first;
            std::cout << "\n";
        }
        else if(dtDataType == DATATYPE::DOUBLE)
        {
            std::cout << "type:\t DOUBLE\n";
        }
        else if(dtDataType == DATATYPE::BOOL)
        {
            std::cout << "type:\t BOOL\n";
        }
    }

    // featurePtr

private:
    std::map<std::string, int> mapFeature;

    std::string strFeatureName;
    
    DATATYPE dtDataType;

    int nColumnWidth;
};

DATATYPE checkType(std::string str);
bool isNumber(std::string s);

class dataframe;
using dataframePtr = std::shared_ptr<dataframe>;

class dataframe : public std::enable_shared_from_this<dataframe>
{
public:
    dataframe(std::string filename);

    dataframe();

    dataframe(dataframePtr dptr, std::vector<std::vector<std::any>> data);

    dataframe(featurePtr _ftptr, std::vector<std::any> vdata);

    std::vector<std::string> getColumns();

    std::vector<std::any> getColData(std::string str);

    std::vector<std::vector<std::any>> getData();

    featurePtr getFeature(std::string str);
    
    void print();

    void splitData(std::vector<float> ratio, std::vector<dataframePtr>& vptr);

    dataframePtr splitFeature(std::vector<std::string> vstr);

    void deleteFeature(std::string strFeature);

    void insertFeature(featurePtr _ftptr, std::vector<std::any> vdata);

    void insertFeature(std::vector<featurePtr> _vftptr, std::vector<std::vector<std::any>> vvdata);

private:
    std::vector<featurePtr> mvpFeature;
    std::vector<std::string> mvFeatureName;
    std::vector<std::vector<std::any>> mmData;

    int mnCols{0};
    int mnRows{0};
};

#endif // DATAFRAME_HPP_