#include "replace.hpp"

int main(int argc, char *argv[])
{
	std::ofstream outfile; //writing (program sending data)
	std::ifstream infile; //reding  (program recieving data)
	std::string new_name;

	if(argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>\n";
		return -1;
	}
	
	if (argv[2][0] == '\0') 
	{ //std::string::find("") always returns 0 will never return npos, always stay in first (You found nothing, at the start (empty) )
		std::cerr << "Error: <s1> cannot be empty.\n";
		return -1;
	}

	infile.open(argv[1]);
	if(!infile.is_open())
	{
		std::cerr << "No Existing File !!" << std::endl;
		return -1;
	}

	new_name = std::string(argv[1]) + ".replace";
	outfile.open(new_name.c_str()); //convert to const char *
	if(!outfile.is_open())
	{
		std::cerr << "Failed open .replace file !!" << std::endl;
		return -1;
	}

	ft_replace(&outfile, &infile, argv[2], argv[3]);
}


/* 
1. File Handling with C++ Streams
2. Reading and Writing File Content
3. String Searching and Replacing (Without replace()) find + substr
4. Error Handling and Edge Cases

→ RAII & scope -- Streams close automatically -- Clean resource management
| Learn how streams work under the hood (RAII principle), and why C++ prefers this approach over C’s
| fopen() / fclose() — this is why the subject forbids “C functions”. 
*/


/*
-> why i should use npos, and why the computer cant hold a string with max size_t ?

*/
