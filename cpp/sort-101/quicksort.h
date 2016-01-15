#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include "basesort.h"

class QuickSort : public BaseSort<int> 
{
public:
	void sort(std::vector<int>& elements) override;

protected:
	virtual int partition(std::vector<int>& elements, int p, int r);
	virtual void quicksort(std::vector<int>& elements, int p, int r);

};

class HoareQuickSort : public QuickSort
{
protected:
	virtual int partition(std::vector<int>& elements, int p, int r) override;
	virtual void quicksort(std::vector<int>& elements, int p, int r) override;
};

class RandomQuickSort : public QuickSort
{
protected:
	int random(int p, int r);
	virtual int partition(std::vector<int>& elements, int p, int r) override;
};

#endif /*__QUICKSORT_H__*/
