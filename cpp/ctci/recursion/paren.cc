#include <string>
#include <sstream>
#include <iostream>


std::string Bracket(std::string bracket) 
{
	std::ostringstream oss;
	oss << "(" << bracket << ")";
	return oss.str();
}

void Brackets(std::string brackets, int num, bool chained)
{
	if (num == 0) {
		std::cout << brackets << ",";
		return;
	}
	if (chained) {
		Brackets(brackets + Bracket(""), num - 1, true);
		Brackets(Bracket(brackets), num - 1, false);
	} else {
		Brackets(brackets + Bracket(""), num - 1, true);
		Brackets(Bracket(brackets), num - 1, false);
		Brackets(Bracket("") + brackets, num - 1, false);
	}
}

int main(int argc, char** argv)
{

	Brackets(Bracket(""), 3, true); std::cout << std::endl;
}


