#ifndef __UTILS_H__
#define __UTILS_H__

#include <vector>
#include <iostream>

template<typename T> void stdprint( std::vector<T> elements ) 
{
	std::cout << "[";
	for (auto e = elements.begin(); e != elements.end(); ++e) {
		std::cout << *e;
		if ((e + 1) != elements.end()) std::cout << ",";
	}
	std::cout << "]\n";
}


#endif /*__UTILS_H__*/
