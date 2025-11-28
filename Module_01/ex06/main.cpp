#include "Harl.hpp"


// Harl = a made-up person who complains a lot.
// pointers to member functions 
// -> means pointer to the methodes in a specific class 

int main()
{
	Harl h;
	h.complain("DEBUG");
    h.complain("INFO");
    h.complain("WARNING");
    h.complain("ERROR");

    // unknown level
    h.complain("RANDOM");
}
