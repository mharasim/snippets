#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

#include "basesort.h"

class BubbleSort : public BaseSort<int>
{
	void sort(std::vector<int>& elements) override;
};

#endif /*__BUBBLESORT_H__*/

