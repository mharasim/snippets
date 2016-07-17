#include <string>
#include <map>
#include <iostream>

bool IsAnagram(std::string str, std::string of)
{
	if (str.size() != of.size()) 
		return false;

	std::map<char,int> counts;
	for (size_t idx = 0; idx < str.size(); ++idx) {
		counts[str[idx]] += 1;
		counts[of[idx]] -= 1;
	}
	for (auto count = counts.begin(); count != counts.end(); ++count) 
		if ((*count).second != 0) 
			return false;
	
	return true;
}

std::string IsAnagramYesNo(std::string str, std::string of)
{
	if (IsAnagram(str,of)) {
		return std::string("Yes");
	} else {
		return std::string("No");
	}
}

int main(int argc, char** argv)
{
	std::string str("abcdefg");
	std::string of1("fcbgead");
	std::string of2("abcddfg");
	std::string of3("abcdef");
	std::string of4("xuahdir");
	
	std::cout << str << " " << of1 << " " << IsAnagramYesNo(str,of1) << std::endl;
	std::cout << str << " " << of2 << " " << IsAnagramYesNo(str,of2) << std::endl;
	std::cout << str << " " << of3 << " " << IsAnagramYesNo(str,of3) << std::endl;
	std::cout << str << " " << of4 << " " << IsAnagramYesNo(str,of4) << std::endl;
}


