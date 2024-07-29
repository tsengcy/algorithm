#ifndef SAMPLE_HPP_
#define SAMPLE_HPP_

#include <type_traits>
#include <iostream>



template<typename T>
typename std::enable_if<std::is_same<T, std::string>::value, void>::type
function(T data)
{
    std::cout << "string: " << data << std::endl;
}

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, void>::type
function(T data)
{
    std::cout << "number: " << data << std::endl;
}






#endif // SAMPLE_HPP_