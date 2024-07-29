#ifndef CART_HPP_
#define CART_HPP_

#include <dataframe/dataframe.hpp>

class CART
{
public:
    CART(dataframePtr _dfptr);

    void train();
protected:
    dataframePtr dfptr;

};



#endif