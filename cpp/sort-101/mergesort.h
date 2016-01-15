#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include "basesort.h"

class MergeSort : public BaseSort<int>
{
public:
	void sort(std::vector<int>& elements) override;

private:
	void merge(std::vector<int>& elements, int p, int q, int r);
	void merge_sort(std::vector<int>& elements, int p, int r);
};

#endif /*__MERGESORT_H__*/
