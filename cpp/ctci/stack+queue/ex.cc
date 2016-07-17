#include <iostream>
#include <vector>
#include <limits>

template<class KeyType> class Node {
public:
	Node(KeyType key)
		:	next_(nullptr),
			key_(key),
			min_(std::numeric_limits<int>::max())
	{}
	Node<KeyType>* next_;
	KeyType key_;
	int min_;
};

typedef Node<int> NodeInt;

void PrintList(NodeInt* root)
{
	NodeInt* curr = root;
	while (curr != nullptr) {
		std::cout << curr->key_ << " ";
		curr = curr->next_;
	}
}

template<class KeyType> class Stack {
public:
	Stack()
		:	top_(nullptr),
			size_(0)
	{}

	void push(KeyType key) {
		Node<KeyType>* node = new Node<KeyType>(key);

		/*
		if (key < top_->min_)
			node->min_ = key;
		else
			node->min_ = top_->min_;
		*/

		node->next_ = top_;
		top_ = node;
		size_++;
	}

	Node<KeyType>* pop() {
		if (top_ == nullptr)
			return nullptr;

		Node<KeyType>* node = top_;
		top_ = top_->next_;
		size_--;
		return node;
	}

	/*
	int min() {
		return top_->min_;
	}
	*/
	bool is_empty() {
		return (top_ == nullptr);
	}

	int top() {
		return (top_->key_);
	}

	Node<KeyType>* get_top() {
		return top_;	
	}
	
	size_t size() {
		return size_;
	}

private:
	Node<KeyType>* top_;
	size_t size_;
};

typedef Stack<int> StackInt;

template<class KeyType> class Queue {
public:
	Queue()
		:	head_(nullptr),
			tail_(nullptr)
	{}

	void enqueue(KeyType key) {
		if (head_ == nullptr) {
			tail_ = new Node<KeyType>(key);
			head_ = tail_;
		} else {
			tail_->next_ = new Node<KeyType>(key);
			tail_ = tail_->next_;
		}
	}

	Node<KeyType>* dequeue() {
		if (head_ == nullptr)
			return nullptr;
	
		Node<KeyType>* node = head_;
		head_ = head_->next_;
		return node;
	}

private:
	Node<KeyType>* head_;
	Node<KeyType>* tail_;
};

class TripleStack {
public:
	const int kNil = -1;

	TripleStack(size_t size)
		:	tab_(size),
			stacks_(3,kNil),
			free_(0)
	{
		for (int i = 0; i < size; ++i) {
			if ((i % 2) == 0) 
				tab_[i] = 0;
			else
				tab_[i] = i + 1;
		}
		tab_[size - 1] = kNil;
	}
	
	int Allocate() {
		if (free_ == kNil)
			return kNil;
		int addr = free_;
		free_ = tab_[free_ + 1];
		tab_[addr] = 0; 
		tab_[addr + 1] = kNil;
		return addr;
	}

	void Free(int addr) {
		tab_[addr + 1] = free_;
		free_ = addr;
	}

	void push(int stack, int key) {
		int node = Allocate();
		if (node != kNil) {
			tab_[node] = key;
			tab_[node + 1] = stacks_[stack];
			stacks_[stack] = node;
		}
	}

	int pop(int stack) {
		if (stacks_[stack] == kNil) 
			return kNil;

		int key = tab_[stacks_[stack]];
		int addr = stacks_[stack];
		stacks_[stack] = tab_[stacks_[stack] + 1];
		Free(addr);
		return key;
	}

	void dump() {
		for (auto i = tab_.begin(); i != tab_.end(); ++i)
			std::cout << *i << " ";
		std::cout << std::endl;
	}

	void dump_stacks() {
		std::cout << "h0: " << stacks_[0]
			<< " h1: " << stacks_[1] 
			<< " h2: " << stacks_[2]
			<< std::endl;
	}

private:
	std::vector<int> tab_;
	std::vector<int> stacks_;
	int free_;

};


void SortStack(StackInt& stack) 
{
	int key = stack.pop()->key_;
	if (stack.is_empty()) {
		stack.push(key);
	} else {
		SortStack(stack);
		if (key < stack.top()) {
			int tmp = key;
			key = stack.pop()->key_;
			stack.push(tmp);
		} 
		stack.push(key);
	}
}


int main(int argc, char** argv)
{
	TripleStack ts(10);
	ts.dump();
	ts.dump_stacks();

	ts.push(0,1);	
	ts.dump();
	ts.dump_stacks();
	ts.push(0,2);
	ts.dump();
	ts.dump_stacks();
	ts.push(0,3);
	ts.dump();
	ts.dump_stacks();
	//ts.push(1,4);
	//ts.push(2,7);
	/*
	ts.push(1,5);
	ts.push(2,8);
	
	ts.push(1,6);
	ts.push(2,9);
	*/

	std::cout << "s0: " << ts.pop(0) << std::endl;
	ts.dump();
	ts.dump_stacks();
	std::cout << "s0: " << ts.pop(0) << std::endl;
	ts.dump();
	ts.dump_stacks();
	std::cout << "s0: " << ts.pop(0) << std::endl;
	ts.dump();
	ts.dump_stacks();
	//std::cout << "s1: " << ts.pop(1) << ts.pop(1) << ts.pop(1) << std::endl;
	//std::cout << "s2: " << ts.pop(2) << ts.pop(2) << ts.pop(2) << std::endl;
	StackInt s;
	s.push(3);
	s.push(1);
	s.push(4);
	s.push(2);
	s.push(5);
	
	std::cout << std::endl;
	PrintList(s.get_top());
	std::cout << std::endl;
	
	for (size_t i = 0; i < s.size(); ++i)
		SortStack(s);

	PrintList(s.get_top());
	std::cout << std::endl;
	
}
