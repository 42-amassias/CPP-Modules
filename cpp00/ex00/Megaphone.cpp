#include <iostream>

int	main(int argc, char *argv[])
{
	std::string				str;
	std::string				res;
	std::string::iterator	itr;

	++argv;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (*argv)
		{
			str = *argv++;
			for (itr = str.begin(); itr != str.end(); ++itr)
				res += std::toupper(*itr);
		}
		std::cout << res;
	}
	std::cout << std::endl;
	return (0);
}