#include "stringutils.h"

void splitUsingDelimiter(std::string const & str, char delim, std::vector<std::string>& out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

void replaceOccurancesOf(std::string const & str, char delim, const char* replacement, std::string& out) {
	std::vector<std::string> arr;
	splitUsingDelimiter(str, delim, arr);
	std::string newStr = "";
	for (std::string st : arr) {
		newStr += st + replacement;
	}
	out = newStr;
}
