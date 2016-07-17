#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <stack>
#include <iomanip>
#include <limits>

template<class Key, class CompFun> class BinaryHeap {
public:
	struct Node {
		Node(const Key& k)
			: key(k),
				parent(nullptr),
				left(nullptr),
				right(nullptr)
		{}

		Key key;
		Node* parent;
		Node* left;
		Node* right;
	};
	
	BinaryHeap() 
		:	size_(0),
			root_(nullptr)
	{}

	void heapify(Node* node)
	{
		if (node == nullptr)
			return;

		bool right = false; 
		bool left = false;

		if (node->right != nullptr) 
			right = CompFun()(node->key, node->right->key);

		if (right) {
			if (node->left != nullptr)
				left = CompFun()(node->right->key, node->left->key);
			if (left) right = false;
		} else {
			if (node->left != nullptr)
				left = CompFun()(node->key, node->left->key);
		}
		
		if (!left && !right) return;
		if (left) {
			Key tmp = node->key;
			node->key = node->left->key;
			node->left->key = tmp;
			heapify(node->left);
		} else {
			Key tmp = node->key;
			node->key = node->right->key;
			node->right->key = tmp;
			heapify(node->right);
		}
	}

	Key pop()
	{
		if (root_ == nullptr)
			throw std::runtime_error("out_of_boundary");
		
		Key key;
		if (size_ == 1) {
			key = root_->key;
			delete root_;
			root_ = nullptr;
			size_ = 0;
			return key;
		}
		
		// Last node in heap
		std::stack<bool> rsize = stack_for(size_);
		rsize.pop(); //remove root

		Node* ins = root_;
		while (rsize.size() > 1) {
			bool dir = rsize.top(); rsize.pop();
			if (dir) 
				ins = ins->right;
			else
				ins = ins->left;
		}

		key = root_->key;
		if (rsize.top()) {
			root_->key = ins->right->key;
			delete ins->right;
			ins->right = nullptr;
		} else {
			root_->key = ins->left->key;
			delete ins->left;
			ins->left = nullptr;
		}
		
		size_ -= 1;

		heapify(root_);

		return key;
	}

	std::stack<bool> stack_for(size_t size)
	{
		std::stack<bool> rsize;
		while (size != 0) {
			if ((size & 1) == 1)
				rsize.push(true);
			else
				rsize.push(false);

			size = size >> 1;
		}
		return rsize;
	}

	void increase_key(Node* node, Key key)
	{
		if (CompFun()(key, node->key)) 
			return;
		node->key = key;
		Node* n = node;
		while (n->parent != nullptr && (CompFun()(n->parent->key, n->key))) {
			Key tmp = n->parent->key;
			n->parent->key = n->key;
			n->key = tmp;
			n = n->parent;
		}
	}

	void push(const Key& key) 
	{
		Node* node = new Node(std::numeric_limits<Key>::lowest());
		if (root_ == nullptr) {
			root_ = node;
			increase_key(node, key);
			size_ += 1;
			return; 
		}
		
		size_t size = size_ + 1;
		std::stack<bool> rsize = stack_for(size);
		rsize.pop(); // remove root
		
		Node* ins = root_;
		while (rsize.size() > 1) {
			bool dir = rsize.top(); rsize.pop();
			if (dir) 
				ins = ins->right;
			else
				ins = ins->left;
		}
		if (rsize.top()) 
			ins->right = node;
		else
			ins->left = node;
		node->parent = ins;

		increase_key(node, key);

		size_ += 1;
	}
	
	void print(Node* node, int indent, std::string prefix)
	{
		if (node == nullptr) return;

		if (indent > 0) 
			std::cout << std::setw(indent) << ' ';
		std::cout << prefix << node->key << "\n ";

		if (node->right != nullptr) print(node->right, indent+4, "/ ");
		if (node->left != nullptr) print(node->left, indent+4, "\\ ") ; 
	}

	void print()
	{
		print(root_, 0, "");
	}
private:
	size_t size_;
	Node* root_;

};

class MyComp {
public:
	bool operator()(const int& l, const int& r) const
	{
		return (l < r);
	}
};

int main()
{
	std::cout << "Heap: " << std::endl;
	BinaryHeap<int, MyComp> bh;
	bh.push(5);
	bh.print();
	std::cout << std::endl;
	bh.push(6);
	bh.print();
	std::cout << std::endl;
	bh.push(7);
	bh.print();
	std::cout << std::endl;
	bh.push(1);
	bh.print();
	std::cout << std::endl;
	bh.push(3);
	bh.print();
	std::cout << std::endl;
	bh.push(0);
	bh.print();
	std::cout << std::endl;
	bh.push(2);
	bh.print();
	std::cout << std::endl;
	bh.pop();
	bh.print();
	std::cout << std::endl;
	bh.pop();
	bh.print();
	std::cout << std::endl;
	bh.pop();
	bh.print();
	std::cout << std::endl;
}
