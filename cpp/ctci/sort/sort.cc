#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <cmath>

template<typename T> void stdprint( std::vector<T> elements ) 
{
	std::cout << "[";
	for (auto e = elements.begin(); e != elements.end(); ++e) {
		std::cout << *e;
		if ((e + 1) != elements.end()) std::cout << ",";
	}
	std::cout << "]\n";
}

void MergeSorted(int a[], int b[], size_t n, size_t m)
{
		size_t iab = n + m - 1;
		size_t ia = n - 1;
		size_t ib = m - 1;
		
		while (ia > 0 && ib > 0) {
			if (a[ia] > b[ib]) {
				a[iab] = a[ia];
				ia = ia - 1;
			} else {
				a[iab] = b[ib];
				ib = ib - 1;
			}
		}

		if (ib > 0) {
			a[iab] = b[ib];
			ib = ib - 1;
		}

}

struct AnagramComparator {
	bool operator()(const std::string& a, const std::string& b) {
		std::string sa = a;
		std::string sb = b;
		std::sort(sa.begin(), sa.end());
		std::sort(sb.begin(), sb.end());
		if (sa.compare(sb) == 0)
			return true;
		return false;
	}
} anagram_comparator;

void AnagramSort(std::vector<std::string>& to_sort)
{
	std::sort(to_sort.begin(), to_sort.end(), anagram_comparator);
}

std::vector<int> MultiMerge(std::vector<std::deque<int>> chunks) 
{
	bool empty = true;
	std::vector<int> res;
	do {
		empty = true;
		int min_vec_index = -1;
		for (size_t v = 0; v < chunks.size(); ++v) {
			if (!chunks[v].empty()) { 
				if (min_vec_index < 0) min_vec_index = v;
				empty = false;
				if (chunks[v].front() < chunks[min_vec_index].front())
					min_vec_index = v;
			}
		}
		if (!empty) {
			res.push_back(chunks[min_vec_index].front());
			chunks[min_vec_index].pop_front();
		}
	} while (!empty);
	return res;
}

int SparseBinary(std::vector<std::string> vs, std::string v, int p, int r) 
{	
	std::cout << "SparseBinary(" << p << "," << r << ")" << std::endl;
	if (r < p) return -1;
	int q = std::floor((p + r)/2); 
	std::cout << "q: " << q << std::endl;
	if (vs[q].compare(v) == 0) return q;

	int right = q;
	while (right < r && vs[right].compare("") == 0) 
		right = right + 1;
	if (vs[right].compare("") == 0) {
		return SparseBinary(vs, v, p, q - 1);
	} else {
		return std::max(SparseBinary(vs, v, p, q - 1), SparseBinary(vs, v, q + 1, r));
	}
}

int CloseBinary(std::vector<int> vs, int v,int p, int r) 
{
	//std::cout << "CloseBinary(" << p << "," << r << ")" << std::endl;
	if (r < p) return -1;
	int q = std::floor((p+r)/2);
	//std::cout << "q: " << q << std::endl;
	if (vs[q] == v) return q;

	int res = -1;
	if (vs[q] > v) {
		res = CloseBinary(vs, v, p, q - 1);
	} else {
		res = CloseBinary(vs, v, q + 1, r);
	}
	
	if (res == -1) {
		if (vs[q] > v) {	
			if (q - 1 < 0) return -2;
			return (q - 1);
		}	
		return q;
	} 

	return res;
}

int main(int argc, char** argv) 
{
	std::vector<std::string> v = { "abcd", "bcad", "xyzf", "auat" };
	stdprint<std::string>(v);
	AnagramSort(v);
	stdprint<std::string>(v);

	std::vector<std::deque<int>> sorts = { { 1, 4, 7, 10 }, { 2, 5, 8, 11}, { 3, 6, 9 } };
	stdprint<int>(MultiMerge(sorts));
	
	std::vector<std::string> sparse = { "abc", "", "", "", "car", "", "", "big", "", "" };
	std::cout << SparseBinary(sparse, "car", 0, sparse.size() - 1) << std::endl;
	std::cout << SparseBinary(sparse, "war", 0, sparse.size() - 1) << std::endl;

	std::vector<int> v1 = { 0, 5, 10, 15, 20 };
	std::vector<int> v2 = { 0, 5, 10, 15 };
	
	std::cout << std::endl << "close: " << CloseBinary(v1,4,0,v1.size()-1) << std::endl;
	std::cout << std::endl << "close: " << CloseBinary(v1,15,0,v1.size()-1) << std::endl;
	std::cout << std::endl << "close: " << CloseBinary(v1,16,0,v1.size()-1) << std::endl;
	std::cout << std::endl << "close: " << CloseBinary(v2,8,0,v2.size()-1) << std::endl;




}
