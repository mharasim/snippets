#include <vector>
#include <utility>
#include <cstdint>
#include <cmath>
#include <iostream>

void RotateMatrix(std::vector<std::vector<uint32_t>>& m) 
{	
	std::vector<std::pair<size_t,size_t>> nodes;
	for (size_t x0 = 0; x0 < m.size(); ++x0) 
		for (size_t y0 = 0; y0 < m[x0].size(); ++y0) 
			if (m[x0][y0] == 0) nodes.push_back(std::pair<size_t,size_t>(x0,y0));
		
	for (auto node = nodes.begin(); node != nodes.end(); ++node) {
		for (size_t x = 0; x < m.size(); ++x) 
			m[x][(*node).second] = 0;
		for (size_t y = 0; y < m[(*node).first].size(); ++y) 
			m[(*node).first][y] = 0;
	}
}


void PrintMatrix(std::vector<std::vector<uint32_t>>& m)
{
	for (auto x = m.begin(); x != m.end(); ++x) {
		for (auto y = (*x).begin(); y != (*x).end(); ++y)
			std::cout << *y << " ";
		std::cout << std::endl;
	}
}

int main(int argc, char** argv)
{
		std::vector<uint32_t> r1 = { 1, 2, 3, 4, 0 };
		std::vector<uint32_t> r2 = { 1, 2, 3, 4, 5 };
		std::vector<uint32_t> r3 = { 0, 2, 3, 4, 5 };
		std::vector<uint32_t> r4 = { 1, 2, 3, 4, 5 };
		std::vector<uint32_t> r5 = { 1, 2, 3, 4, 5 };
	
		std::vector<std::vector<uint32_t>> m;
		m.push_back(r1);
		m.push_back(r2);
		m.push_back(r3);
		m.push_back(r4);
		m.push_back(r5);

		PrintMatrix(m);
		RotateMatrix(m);
		std::cout << std::endl;
		PrintMatrix(m);
}

