#include "heapsort.h"
#include "bubblesort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "insertionsort.h"
#include "countingsort.h"

#include "utils.h"

int main() 
{

	/*
	std::vector<int> vec = { 4,3,7,9,2,10,0,23,8,9,54 };
	std::vector<int> tvec = vec;
	
	stdprint(tvec);

	HeapSort hs; hs.sort(tvec);

	stdprint(tvec);
	
	std::vector<unsigned int> a = { 8213,312,612,523,22,7123,822,122,17,51,10,13 };
	std::vector<unsigned int> a2 = { 8213,312,612,523,22,7123,822,122,17,51,10,13 };
	std::vector<unsigned int> b(a.size());
	
	stdprint(a);
	stdprint(a2);

	CountingSort cs(8213); 
	cs.radix(a,4);
	cs.sort(a2);
	stdprint(a);
	stdprint(a2);
	*/
	MergeSort ms;
	std::vector<int> vec = { 4,3,7,9,2,10,0,23,8,9,54 };
	ms.sort(vec);
	stdprint(vec);

	return 1;
}
