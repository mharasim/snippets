#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <stack>
#include <iomanip>
#include <limits>

template<class Key, class HashFun> class HashTab {
public:

	struct KeyContainer {
		KeyContainer(const Key& k, KeyContainer* n)
			: key(k),
				next(n)
		{}

		Key key;
		KeyContainer* next;
	};

	HashTab(size_t m)
		:	m_(m),
			tab_(new KeyContainer*[m_])
	{
		for (int i = 0; i < m_; ++i)
			tab_[i] = nullptr;
	}

	KeyContainer* operator[](const size_t& index)
	{
		return tab_[index];
	}
	
	void insert(const Key& value) 
	{
		size_t h = HashFun()(value);
		if (tab_[h] == nullptr) {
			tab_[h] = new KeyContainer(value, nullptr);
		} else {
			KeyContainer* kc = new KeyContainer(value, tab_[h]);
			tab_[h] = kc;
		}
	}

	KeyContainer* search(const Key& value) 
	{
		size_t h = HashFun()(value);
		if (tab_[h] == nullptr)
			return nullptr;
		KeyContainer* kc = tab_[h];
		while (kc != nullptr) {
			if (kc->key == value)
				return kc;
			kc = kc->next;
		}
		return nullptr;
	}

	void print() 
	{
		for (int i = 0; i < m_; ++i) {
			std::cout << i << ": ";
			KeyContainer* kc = tab_[i];
			while (kc != nullptr) {
				std::cout << kc->key << ",";
				kc = kc->next;
			}
			std::cout << std::endl;
		}
	}

private:
	size_t m_;
	KeyContainer** tab_;

};

template<size_t size> class MyHashFun {
public:
	size_t operator()(const int& value) const
	{
		return (value % size);
	}
};

int main()
{
	HashTab<int, MyHashFun<20>> ht(20);
	ht.insert(5);
	ht.insert(10);
	ht.insert(15);
	ht.insert(20);
	ht.insert(25);
	ht.print();

	if (ht.search(5) != nullptr) 
		std::cout << "Found 5" << std::endl;

	if (ht.search(20) != nullptr) 
		std::cout << "Found 20" << std::endl;

	if (ht.search(10) != nullptr) 
		std::cout << "Found 10" << std::endl;

	if (ht.search(100) != nullptr) 
		std::cout << "Found 100" << std::endl;

	if (ht.search(12) != nullptr) 
		std::cout << "Found 12" << std::endl;
}

