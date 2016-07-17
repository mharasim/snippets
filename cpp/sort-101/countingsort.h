#ifndef __COUNTINGSORT_H__
#define __COUNTINGSORT_H__

#include <vector>

#include "basesort.h"

class CountingSort : public BaseSort<unsigned int>
{
public:
	CountingSort(unsigned int vmax);
	void sort(std::vector<unsigned int>& elements) override;
	void radix(std::vector<unsigned int>& A, unsigned int d);
	
private:
	unsigned int digit(unsigned int value, unsigned int number);

	void csort(std::vector<unsigned int>& A, std::vector<unsigned int>& B, unsigned int vmax);
	void rcsort(std::vector<unsigned int>& A, std::vector<unsigned int>& B, unsigned int d);

	unsigned int _vmax;
};


#endif /*__COUNTINGSORT_H__*/
