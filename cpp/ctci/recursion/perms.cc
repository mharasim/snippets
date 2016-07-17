#include <list>
#include <vector>
#include <string>
#include <iostream>

void Permutate(std::string str, std::string origin, size_t index, std::list<size_t> indexes, std::vector<std::string>& permutations)
{
	if (index >= str.size()) {
		permutations.push_back(str);
		return;
	}

	for (auto idx = indexes.begin(); idx != indexes.end(); ++idx) {
		std::string pstr = str; 
		pstr[*idx] = origin[index];
		std::list<size_t> idxs = indexes;
		idxs.remove(*idx);
		Permutate(pstr, origin, index + 1, idxs, permutations);
	}
}

std::vector<std::string> Permutations(std::string str) 
{
	std::vector<std::string> permutations;
	std::list<size_t> indexes;
	for (int index = 0; index < str.size(); ++index)
		indexes.push_back(index);
	
	Permutate(str, str, 0, indexes, permutations);

	return permutations;
}

int main(int argc, char** argv)
{
	std::string str("abcd");
	std::vector<std::string> perms = Permutations(str);
	for (auto p = perms.begin(); p != perms.end(); ++p)
		std:: cout << *p << std::endl;
}
