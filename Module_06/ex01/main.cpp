#include "Data.hpp"
#include "Serializer.hpp"


int main()
{
    Data* d1 = new Data;
    d1->str = "hello worlddd !";

    std::cout << "D1 string : " << d1->str << std::endl;
    std::cout << "D1 address: " << d1 << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    uintptr_t intraw = Serializer::serialize(d1);
    std::cout << "Serialized integer: " << intraw << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    
    Data* d2 = Serializer::deserialize(intraw);
    std::cout << "D2 string : " << d2->str << std::endl;
    std::cout << "D2 address: " << d2 << std::endl;
    std::cout << "-----------------------------------\n" << std::endl;

    if (d1 == d2) {
        std::cout << "<<<< SUCCESS ! >>>>" << std::endl;
    } else {
        std::cout << "<<<< ERROR !!!! >>>>" << std::endl;
    }

    delete d1;

}

