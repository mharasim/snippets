#include <vector>
#include <cstdint>
#include <cmath>
#include <iostream>

void RotateMatrix(std::vector<std::vector<uint32_t>>& m) 
{
	size_t N = m.size();
	size_t layers = std::floor(N/2);
	for (size_t l = 0; l < layers; ++l) {
		for (size_t x = l; x < (N - 1 - l); ++x) {
			uint32_t tmp_prev = m[l][N - 1 - x];
			m[l][N - 1 - x] = m[x][l];
			uint32_t tmp_next = m[N - 1 - x][N - 1 - l];
			m[N - 1 - x][N - 1 - l] = tmp_prev;
			tmp_prev = m[N - 1 - l][x];
			m[N - 1 - l][x] = tmp_next;
			m[x][l] = tmp_prev;
		}
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
		std::vector<uint32_t> r1 = { 1, 2, 3, 4, 5 };
		std::vector<uint32_t> r2 = { 1, 2, 3, 4, 5 };
		std::vector<uint32_t> r3 = { 1, 2, 3, 4, 5 };
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

