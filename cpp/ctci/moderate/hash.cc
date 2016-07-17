#include <unordered_set>
#include <string>
#include <iostream>

struct S {
	S(std::string n, std::string l)
		:	name(n),
			last(l)
	{}
	std::string name;
	std::string last;
};

bool operator==(const S& l, const S& r) 
{
	if ((l.name.compare(r.name) == 0) &&
			(l.last.compare(r.last) == 0))
		return true;
	return false;
}

struct I {
	I(int n1, int n2)
		:	num1(n1),
			num2(n2)
	{}
	int num1;
	int num2;
};

bool operator==(const I& l, const I& r)
{
	if (l.num1 == r.num1 && l.num2 == r.num2)
		return true;
	return false;
}

struct SHash {
	std::size_t operator()(const S& s) const
	{
		std::size_t h1 = std::hash<std::string>()(s.name);
		std::size_t h2 = std::hash<std::string>()(s.last);
		return h1 ^ (h2 << 1);
	}
};

struct IHash {
	std::size_t operator()(const I& i) const
	{
		std::size_t h1 = std::hash<int>()(i.num1);
		std::size_t h2 = std::hash<int>()(i.num2);
		return h1 ^ (h2 << 1);
	}
};


int main()
{
	// Priority queue (<queue>):
	std::priority_queue<int> max_heap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
	// top(), pop(), push()

	// queue (<queue>):
	std::queue<int> q;
	// push (back), pop (front), front, back
	
	// stack (<stack>):
	std::stack<int> s;
	// top(), push (front), pop (front),
	
	// Hash table:
	std::unordered_set<S,SHash> s_set;
	std::unordered_set<I,IHash> i_set;
	// insert, find, erase
	
	// Set (<set>):
	std::set<int> ss;
	// std::set<int, std::greater<int>> std::set<int, MyFunctor>
	// unique sorted, rb-tree
	
	// push_back/front pop_back/front, 
	std::deque<int> dq; // + operator [] O(1)
	std::list<int> li;
		

	s_set.insert(S("abc","xyz"));
	s_set.insert(S("abc","abz"));
	s_set.insert(S("aza","zaz"));

	i_set.insert(I(1,2));
	i_set.insert(I(10,2));
	i_set.insert(I(2,12));

	if (s_set.find(S("abc","xyz")) != s_set.end())
		std::cout << "OK S" << std::endl;

	if (i_set.find(I(10,2)) != i_set.end())
		std::cout << "OK I" << std::endl;
}



