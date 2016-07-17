#include <iostream>
#include <vector>

typedef std::vector<size_t> Factorial;

void Print(Factorial factorial)
{
	for (auto f = factorial.begin(); f != factorial.end(); ++f)
		std::cout << *f << ",";
	std::cout << std::endl;
}

void Factor(size_t number, size_t max_f, Factorial factorial) 
{
	if (number == 0) {
		Print(factorial);
		return;
	}

	if (number >= 25 && max_f >= 25) {
		Factorial f = factorial;
		f.push_back(25);
		Factor(number - 25, 25, f); 
	}

	if (number >= 10 && max_f >= 10) {
		Factorial f = factorial;
		f.push_back(10);
		Factor(number - 10, 10, f); 
	}

	if (number >= 5 && max_f >= 5) {
		Factorial f = factorial;
		f.push_back(5);
		Factor(number - 5, 5, f); 
	}

	if (number >= 1 && max_f >= 1) {
		Factorial f = factorial;
		f.push_back(1);
		Factor(number - 1, 1, f); 
	}
}

int main(int argc, char** argv)
{
	Factorial f;
	Factor(35, 25, f);
}
