#include "countingsort.h"

#include <iostream>
#include <cmath>

CountingSort::CountingSort(unsigned int vmax):
	_vmax(vmax)
{}

void CountingSort::sort(std::vector<unsigned int>& elements)
{
	std::vector<unsigned int> b(elements.size());
	csort(elements, b, _vmax);
	elements = b;
}

void CountingSort::csort(std::vector<unsigned int>& A, std::vector<unsigned int>& B, unsigned int vmax)
{
	// A - elements to be sorted (integers [0, vmax])
	// B - sorting result (values from A inserted on C index)
	// C - index is value from A,
	//	* First it is filled with number of repetitions for each value,
	//	* Next 
	std::vector<unsigned int> C(vmax + 1);
	for (auto c = C.begin(); c != C.end(); ++c) 
		*c = 0;
	for (auto a = A.begin(); a != A.end(); ++a) 
		++C[*a];
	for (auto c = C.begin() + 1; c != C.end(); ++c) 
		*c += *(c - 1);

	for (auto a = A.rbegin(); a != A.rend(); ++a) { 
		C[*a] -= 1;
		B[C[*a]] = *a; 
	}
}

unsigned int CountingSort::digit(unsigned int value, unsigned int number) 
{
	unsigned int power = std::floor(std::pow(10,number));
	if (value < power) return 0;
	
	unsigned int digit = std::floor((value % (power*10)) / power);
	return digit;
}

void CountingSort::rcsort(std::vector<unsigned int>& A, std::vector<unsigned int>& B, unsigned int d)
{
	std::vector<unsigned int> C(10);

	for (auto c = C.begin(); c != C.end(); ++c) 
		*c = 0;

	//std::cout << "C: "; print(C);

	for (auto a = A.begin(); a != A.end(); ++a) 
		++C[digit(*a,d)];

	//std::cout << "A: "; print(A);
	//std::cout << "C: "; print(C);

	for (auto c = C.begin() + 1; c != C.end(); ++c) 
		*c += *(c - 1);

	//std::cout << "C: "; print(C);

	for (auto a = A.rbegin(); a != A.rend(); ++a) { 
		B[C[digit(*a,d)] - 1] = *a; 
		--C[digit(*a,d)];
	}

}


void CountingSort::radix(std::vector<unsigned int>& A, unsigned int d)
{
	std::vector<unsigned int> B;

	for (unsigned int i = 0; i < d; ++i) {
		B = std::vector<unsigned int>(A.size());
		rcsort(A, B, i);
		A = B;
	}
}

/*
int main()
{
	std::vector<unsigned int> a = { 8213,312,612,523,22,7123,822,122,17,51,10,13 };
	std::vector<unsigned int> b(a.size());
	
	print(a);
	radix(a,4);
	print(a);
}
*/
