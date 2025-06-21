#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";	
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string word = argv[i];
		for (unsigned int j = 0; j < word.length(); j++)
			std::cout  << (char) std::toupper(argv[i][j]);	
	}
	std::cout << std::endl;
	return (0);
}
