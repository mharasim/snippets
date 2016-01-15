#include "heapsort.h"
#include "bubblesort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "insertionsort.h"

#include "utils.h"

int main() 
{
	std::vector<int> vec = { 4,3,7,9,2,10,0,23,8,9,54 };
	std::vector<int> tvec = vec;
	
	stdprint(tvec);

	HeapSort hs; hs.sort(tvec);

	stdprint(tvec);
	
	return 1;
}
