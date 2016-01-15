#ifndef __BASESORT_H__
#define __BASESORT_H__

#include <vector>

template<class T> class BaseSort
{
public:
	virtual void sort(std::vector<T>& elements) = 0; 
};

#endif /*__BASESORT_H__*/
