#pragma once
#include <string>
#include <vector>
void splitUsingDelimiter(std::string const &str, char delim,
		std::vector<std::string> &out);

void replaceOccurancesOf(std::string const & str, char delim,
	const char* replacement, std::string& out);
		