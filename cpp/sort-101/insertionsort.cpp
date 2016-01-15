#include "insertionsort.h"

void InsertionSort::sort(std::vector<int>& elements)
{
	for (unsigned int n_el = 1; n_el < elements.size(); ++n_el) {
		int el = n_el - 1;
		int v = elements[n_el];
		while (el > 0 && elements[el] > v) {
			elements[el + 1] = elements[el];
			--el;
		}	
		elements[el + 1] = v;
	}
}
