#include <deque>
#include <iostream>

typedef std::deque<int> Set;
typedef std::deque<Set> SetOfSets;

SetOfSets BuildSubsets(Set set)
{
	SetOfSets subsets;
	for (auto e = set.begin(); e != set.end(); ++e) {
		Set s;
		s.push_back(*e);
		subsets.push_back(s);
	}
	return subsets;
}

Set Merge(Set set, Set into)
{
	auto e = set.back(); set.pop_back();
	into.push_back(e);
	return into;
}

void Subsets(Set set, SetOfSets sets, SetOfSets& subsets)
{
	if (sets.empty())
		return;

	SetOfSets sos;
	while (!sets.empty()) {
		Set s = sets.front(); sets.pop_front();
		subsets.push_back(Merge(s, set));
		sos.push_back(Merge(s, set));
	}

	Set next_set = sos.front(); sos.pop_front();
	Subsets(next_set, sos, subsets);
}

int main(int argc, char** argv)
{
	Set set = { 1, 2, 3, 4, 5 };
	SetOfSets init_sets = BuildSubsets(set);
	SetOfSets subsets;
	
	while (!init_sets.empty()) {
		Set s = init_sets.front(); init_sets.pop_front();
		subsets.push_back(s);
		Subsets(s, init_sets, subsets);
	}
	
	std::cout << "Set: " << std::endl;
	for (auto e = set.begin(); e != set.end(); ++e) std::cout << *e << ",";
	std::cout << std::endl;

	std::cout << "Subsets: " << std::endl;
	for (auto s = subsets.begin(); s != subsets.end(); ++s) {
		for (auto e = (*s).begin(); e != (*s).end(); ++e) std::cout << *e << ",";
		std::cout << std::endl;
	}

}
