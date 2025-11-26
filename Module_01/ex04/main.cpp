#include <iostream>
#include <fstream> 
#include <string.h> 

int main(int argc, char *argv[])
{
	std::ofstream outfile; //writing (program sending data)
	std::ifstream infile; //reding  (program recieving data)
	std::string line;
	std::string new_name;
	size_t		position;
	size_t		prev_position;

	if(argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>\n";
		return -1;
	}

	infile.open(argv[1]);
	if(!infile.is_open())
	{
		std::cerr << "No Existing File !!" << std::endl;
		return -1;
	}

	new_name = argv[1] + std::string(".replace");
	outfile.open(new_name.c_str()); //convert to const char *
	if(!outfile.is_open())
	{
		std::cerr << "Failed open .replace file !!" << std::endl;
		return -1;
	}

	while (std::getline(infile, line))
	{
		outfile << line << std::endl;
		prev_position = 0;
		position = line.find(argv[2]); //41
		while (position != std::string::npos)
		{
			outfile << line.substr(prev_position, (position - prev_position));
			std::cout << "substring from (" << prev_position + 1  << ") ->" ;
			std::cout << "(" << (position - prev_position) +1<< ") CHAR\n";
			
			outfile << argv[3];
			std::cout << "write argv[3] : " << argv[3] << "\n";
			
			prev_position = position + strlen(argv[2]) ; // 41 + 8 = 49
			std::cout << "update prev_pos = " << prev_position + 1 << "\n";
			
			position = line.find(argv[2], prev_position); // 51
			std::cout << "update position = " << position + 1 << "\n"; 

		}
		outfile << line.substr(prev_position) << std::endl; // we dont do from prev->position , cuz find will return npos(max size_t)
		std::cout << "remaining : " << line.substr(prev_position) << std::endl; // we dont do from prev->position , cuz find will return npos(max size_t)

		std::cout << "----------------------------------\n";
	}

}


/* 
outfile << line.substr(prev_POSS



*/


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

// probleem hooww to find the next substring