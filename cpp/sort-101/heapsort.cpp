#include "heapsort.h"

void HeapSort::sort(std::vector<int>& elements)
{
	build_max_heap(elements); // elements[0] is max

	unsigned int hsize = elements.size();

	for (int i = (elements.size() - 1); i >= 1; --i) {
		// elements[n] <-> elements[0];
		int tmp = elements[0];
		elements[0] = elements[i];
		elements[i] = tmp;

		// restore heap for [0, n - 1]
		max_heapify(elements, 0, --hsize);
	}
}
	
void HeapSort::max_heapify(std::vector<int>& elements, unsigned int i, unsigned int hsize)
{
	unsigned int l = left(i); 
	unsigned int r = right(i);
	unsigned int largest;

	if (l < hsize && elements[l] > elements[i]) largest = l;
	else largest = i;

	if (r < hsize && elements[r] > elements[largest]) largest = r;

	if (i != largest) {
		int tmp = elements[i];
		elements[i] = elements[largest];
		elements[largest] = tmp;

		max_heapify(elements, largest, hsize);
	}
}

void HeapSort::build_max_heap(std::vector<int>& elements)
{
	int last_node = std::floor(elements.size()/2) - 1;
	for (int i = last_node; i >= 0; i--) max_heapify(elements, i, elements.size());
}

