#include <iostream>
#include "Array.hpp"



int main() 
{
    try {
        Array<int> myArr(5);
        std::cout << "Size: " << myArr.size() << std::endl;
        myArr[0] = 42;
        std::cout << "Element 0: " << myArr[0] << std::endl;
        
        std::cout << myArr[10] << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
    return 0;
}