#include "replace.hpp"

void ft_replace(std::ofstream *outfile, std::ifstream *infile, const char *s1, const char *s2)
{
	std::string line;
	size_t		position;
	size_t		prev_position;

	while (std::getline(*infile, line))
	{
		prev_position = 0;
		position = line.find(s1);
		while (position != std::string::npos)
		{
			*outfile << line.substr(prev_position, (position - prev_position));
			*outfile << s2;			
			prev_position = position + strlen(s1);	
			position = line.find(s1, prev_position);
		}
		*outfile << line.substr(prev_position) << std::endl;
	}
}
