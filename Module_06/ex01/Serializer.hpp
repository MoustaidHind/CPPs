#pragma once


#include <iostream>


class Serializer.
{
private:
	Serializer(/* args */);
	Serializer(const Serializer&);
	const Serializer operator==(const Serializer&);
	~Serializer(){};

public:
	static uintptr_t serialize(Data* ptr); // It takes a pointer and converts it to the unsigned integer type uintptr_t.
	static Data* deserialize(uintptr_t raw); // It takes an unsigned integer parameter and converts it to a pointer to Data.


};
