#include "replace.hpp"

int main(int argc, char *argv[])
{
	std::ofstream outfile; //writing - program sending data
	std::ifstream infile; //reding - program receiving data
	std::string new_name;

	if(argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>\n";
		return -1;
	}
	if (argv[2][0] == '\0') 
	{
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
	outfile.open(new_name.c_str());
	if(!outfile.is_open())
	{
		std::cerr << "Failed open .replace file !!" << std::endl;
		return -1;
	}
	
	ft_replace(&outfile, &infile, argv[2], argv[3]);

	outfile.close();
	infile.close();
}

