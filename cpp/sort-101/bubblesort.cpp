#include "bubblesort.h"

void BubbleSort::sort(std::vector<int>& elements)
{
	for (auto i = elements.begin(); i != elements.end(); i++)
		for (auto j = elements.end() - 1; j != i; j--)
			if (*j < *(j - 1)) { int tmp = *(j - 1); *(j-1) = *j; *j = tmp; } 
}
