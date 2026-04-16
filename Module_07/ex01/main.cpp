#include "iter.hpp"

void printInt(int &n) {
    std::cout << n << " ";
};

void increment(int &n) {
    n++;
};

template <typename T>
void printElement(T &x) {
    std::cout << x << " ";
};

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = 5;

    std::cout << "-------------------------------" << std::endl;
    std::cout << "Original Integers: ";
    ::iter(intArray, intLen, printInt); 
    std::cout << "\n-------------------------------" << std::endl;

    ::iter(intArray, intLen, increment);
    std::cout << "Incremente Integers: ";
    ::iter(intArray, intLen, printInt);
    std::cout << "\n-------------------------------" << std::endl;

    std::string strArray[] = {"Hello", "World", "1337"};
    size_t strLen = 3;
    
    std::cout << "Strings: ";
    ::iter(strArray, strLen, printElement<std::string>); 
    std::cout << "\n-------------------------------" << std::endl;


    return 0;
}