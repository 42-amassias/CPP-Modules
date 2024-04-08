#include <iostream>
#include <fstream>
#include <cstring>

#define ARG_PN 0
#define ARG_FILE 1
#define ARG_S1 2
#define ARG_S2 3

static void	_perror(
				int n,
				...
				)
{
	std::string	str;
	va_list		list;

	va_start(list, n);
	while (n--)
		str.append(va_arg(list, const char *));
	va_end(list);
	perror(str.c_str());
}

static bool	_open_files(
				const char *file,
				const char *pn,
				std::ifstream &ifs,
				std::ofstream &ofs
				)
{
	ifs.open(file);
	if (!ifs.good())
	{
		_perror(3, pn, ": ", file);
		return (true);
	}
	ofs.open(std::string(file).append(".replace").c_str());
	if (!ofs.good())
	{
		ifs.close();
		_perror(4, pn, ".replace", ": ", file);
		return (true);
	}
	return (false);
}

static void	_replace(
				std::ifstream &ifs,
				std::ofstream &ofs,
				const char *to_find,
				const char *replacement
				)
{
	std::string	content;
	size_t		index;
	size_t		len;

	if (!std::getline(ifs, content, '\0'))
		return ;
	len = std::string(to_find).length();
	do
	{
		index = content.find(to_find);
		if (index == std::string::npos)
			break ;
		content.erase(index, len);
		content.insert(index, std::string(replacement));
	} while (true);
	ofs << content;
}

int	main(
		int argc,
		char *argv[]
		)
{
	std::ifstream	ifs;
	std::ofstream	ofs;

	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments." << std::endl;
		return (1);
	}
	if (_open_files(argv[ARG_FILE], argv[ARG_PN], ifs, ofs))
		return (1);
	_replace(ifs, ofs, argv[ARG_S1], argv[ARG_S2]);
	ofs.close();
	ifs.close();
	return (0);
}
