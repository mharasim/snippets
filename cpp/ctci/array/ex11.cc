#include <map>
#include <string>
#include <iostream>

#include <cmath>
#include <cstdint>

bool HasUniqueChars(std::string str) 
{
	std::map<char, bool> char_map;
	for (auto c = str.begin(); c != str.end(); ++c) {
		if (char_map.find(*c) != char_map.end()) 
			return false;
		char_map[*c] = true;
	}
	return true;
}

bool HasUniqueChars2(std::string str) 
{
	for (auto c = str.begin(); c != str.end(); ++c) {
		for (auto sc = str.begin(); sc != str.end(); ++sc) {
			if (sc == c) continue;
			if (*sc == *c) 
				return false;
		}
	}
	return true;
}

bool HasUniqueChars3(std::string str) 
{
	uint32_t tab = 0;
	for (auto c = str.begin(); c != str.end(); ++c) {
		int pos = int{*c} - int{'a'};
		if (((tab >> pos) & 1) == 1) 
			return false;
		tab = tab | static_cast<int32_t>(std::pow(2, pos));
	}
	return true;
}


int main(int argc, char** argv)
{
	std::string test1 = "Test string";
	std::string test2 = "Abcdefgh";

	if (HasUniqueChars3(test1)) {
		std::cout << test1 << ": Is unique" << std::endl;
	} else {
		std::cout << test1 << ": Not unique" << std::endl;
	}

	if (HasUniqueChars3(test2)) {
		std::cout << test2 << ": Is unique" << std::endl;
	} else {
		std::cout << test2 << ": Not unique" << std::endl;
	}
}
