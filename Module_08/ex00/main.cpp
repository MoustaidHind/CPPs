#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    std::cout << "-----------Vector--------" << std::endl;
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try {
        std::vector<int>::iterator val = easyfind(v, 20);
        std::cout << "Value found: " << *val << std::endl;
        
        easyfind(v, 42);
    } catch (const std::exception& e) {
        std::cerr << "Error: Value not found ! " << std::endl;
    }

    std::cout << "\n-----------list--------" << std::endl;
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    try {
        std::list<int>::iterator val = easyfind(l, 3);
        std::cout << "Value found: " << *val<< std::endl;
        
        easyfind(l, -5);
    } catch (const std::exception& e) {
        std::cerr << "Error: Value not found !" << std::endl;
    }

    return 0;
}