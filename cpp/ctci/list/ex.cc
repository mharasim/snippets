#include <iostream>
#include <cmath>

template<class KeyType> class Node {
public:
	Node(KeyType key)
		:	next_(nullptr),
			key_(key),
			visited_(false)
	{}
	Node<KeyType>* next_;
	KeyType key_;
	bool visited_;
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

void RemoveDuplicates(NodeInt* root) 
{
	NodeInt* last = nullptr;
	while (root != last) {
		NodeInt* curr = root;
		NodeInt* iter = root;
		while (iter->next_ != nullptr) {
			if (iter->next_->key_ == curr->key_) {
				//Delete next
				NodeInt* tmp = iter->next_;
				iter->next_ = iter->next_->next_;
				delete tmp;
			}
			if (iter->next_ != nullptr)
				iter = iter->next_;
		}
		// Remove current and put it ad the end
		root = root->next_;
		curr->next_ = nullptr;
		iter->next_ = curr;
		if (last == nullptr)
			last = iter->next_;	
	}
}

NodeInt* NthToLast(NodeInt* root, size_t n)
{
	NodeInt* curr = root;
	size_t count = 0;

	while (curr != nullptr) {
		curr = curr->next_;
		count = count + 1;
	}
	curr = root;
	while (count > n) {
		curr = curr->next_;
		count = count - 1;
	}
	return curr;
}

NodeInt* NthToLastR(NodeInt* root, size_t& n)
{
	if (root == nullptr) 
		return nullptr; 
	NodeInt* res = NthToLastR(root->next_, n);
	n = n - 1;
	if (n == 0)
		return root;
	else
		return res;
}

bool RemoveNode(NodeInt* node) 
{
	if (node == nullptr || node->next_ == nullptr)
		return false;
	
	node->key_ = node->next_->key_;
	NodeInt* tmp = node->next_;
	node->next_ = node->next_->next_;
	delete tmp;

	return true;
}

NodeInt* SumNodes(NodeInt* left, NodeInt* right)
{
	if (left == nullptr && right == nullptr)
		return nullptr;

	int carry = 0;
	NodeInt* res = nullptr;
	NodeInt* tail = nullptr;
	NodeInt* l = left;
	NodeInt* r = right;

	while (l != nullptr || r != nullptr) {
		int a = (l == nullptr) ? 0 : l->key_;
		int b = (r == nullptr) ? 0 : r->key_;
		int d = (a + b + carry) % 10;
		carry = std::floor((a + b + carry) / 10);

		if (res == nullptr) {
			res = new NodeInt(d);
			tail = res;
		} else {
			tail->next_ = new NodeInt(d);
			tail = tail->next_;
		}

		l = l->next_;
		r = r->next_;
	}
	if (carry != 0)
		tail->next_ = new NodeInt(carry);
		
	return res;
}

NodeInt* CycleDetect(NodeInt* root)
{
	if (root == nullptr)
		return nullptr;

	NodeInt* curr = root;
	curr->visited_ = true;
	while (curr->next_ != nullptr) {
		if (curr->next_->visited_)
			return curr;
		else
			curr->next_->visited_ = true;
		curr = curr->next_;
	}
	return nullptr;
}

int main(int argc, char** argv)
{
	NodeInt* root = nullptr;
	NodeInt* n1 = new NodeInt(0);
	NodeInt* n2 = new NodeInt(1);
	NodeInt* n3 = new NodeInt(2);
	NodeInt* n4 = new NodeInt(3);
	NodeInt* n5 = new NodeInt(2);
	NodeInt* n6 = new NodeInt(1);
	NodeInt* n7 = new NodeInt(7);
	NodeInt* n8 = new NodeInt(6);
	NodeInt* n9 = new NodeInt(0);

	root = n1; 
	n1->next_ = n2;
	n2->next_ = n5;
	n5->next_ = n4;
	n4->next_ = n3;
	n3->next_ = n6;
	n6->next_ = n7;
	n7->next_ = n8;
	n8->next_ = n9;
	
	PrintList(root);
	RemoveDuplicates(root);
	std::cout << std::endl;
	PrintList(root);
	std::cout << std::endl;
	std::cout << NthToLast(root,3)->key_;
	std::cout << std::endl;

	size_t cnt = 4;
	std::cout << NthToLastR(root,cnt)->key_;
	std::cout << std::endl;

	RemoveNode(n2);
	PrintList(root);

	NodeInt* sum = SumNodes(root,root);
	std::cout << std::endl;
	PrintList(sum);
	std::cout << std::endl;

	NodeInt* root_corr = new NodeInt(0);
	NodeInt* nc1 = new NodeInt(1);
	root_corr->next_ = nc1;
	NodeInt* nc2 = new NodeInt(2);
	nc1->next_ = nc2;
	NodeInt* nc3 = new NodeInt(3);
	nc2->next_ = nc3;
	NodeInt* nc4 = new NodeInt(4);
	nc3->next_ = nc4;
	nc4->next_ = nc2;

	NodeInt* c = CycleDetect(root_corr);
	if (c != nullptr)
		std::cout << "Cycle: " << c->key_ << std::endl;
	std::cout << std::endl;
	
}
