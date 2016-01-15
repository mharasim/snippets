#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

#include <cmath>

#include "basesort.h"

class HeapSort : public BaseSort<int>
{
public:
	void sort(std::vector<int>& elements) override;
	
private:
	/** Inline */
	int parent(int i) const
	{ return std::floor((i - 1) / 2); }

	int right(int i) const
	{ return (2*i + 2); } 

	int left(int i) const 
	{ return  (2*i + 1); }


	void max_heapify(std::vector<int>& elements, unsigned int i, unsigned int hsize);
	void build_max_heap(std::vector<int>& elements);
};

#endif /*__HEAPSORT_H__*/

