#include "iter.hpp"



#include <iostream>

// A regular function that works with integers
void printInt(int &n) {
    std::cout << n << " ";
}

// A regular function that works with strings
void printString(std::string &s) {
    std::cout << s << " ";
};

// A template function to test if iter can take an instantiated template [cite: 195]
template <typename T>
void printElement(T &x) {
    std::cout << x << " ";
}

// A function that modifies the element (to test non-const behavior)
void increment(int &n) {
    n++;
}

int main() {
    // Test 1: Integer array with a regular function
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = 5;
    
    std::cout << "Original Integers: ";
    ::iter(intArray, intLen, printInt); // Using :: to ensure it uses your global template
    std::cout << std::endl;

    // Test 2: Incrementing values (testing modification)
    ::iter(intArray, intLen, increment);
    std::cout << "Incremented Integers: ";
    ::iter(intArray, intLen, printInt);
    std::cout << std::endl;

    // Test 3: String array with a template function [cite: 195]
    std::string strArray[] = {"Hello", "1337", "Hind"};
    size_t strLen = 3;
    
    std::cout << "Strings: ";
    // We must explicitly instantiate the template function passed as the 3rd parameter
    ::iter(strArray, strLen, printElement<std::string>); 
    std::cout << std::endl;


    return 0;
}