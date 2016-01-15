#ifndef __INSERTIONSORT_H__
#define __INSERTIONSORT_H__

#include "basesort.h"

class InsertionSort : public BaseSort<int>
{
public:
	void sort(std::vector<int>& elements) override;
};

#endif /*__INSERTIONSORT_H__*/
