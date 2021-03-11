#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
#include <algorithm>



int main(int argc, char** argv)
{
	std::string data = " text text 28.09.2001 text text 8-02-2001 text text 11/03/2021 text text text ";
	static const std::regex pattern(R"((0*[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20\d\d))");
	std::sregex_iterator begin(data.cbegin(), data.cend(), pattern);
	std::sregex_iterator end;

	std::for_each(begin, end, [](const std::smatch& m)
		{
			std::cout << m[0] << std::endl;
		});

	system("pause");

	return EXIT_SUCCESS;
}