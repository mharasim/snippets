#include "tree.h"

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <stack>

int max_depth(BSTNode* node)
{
	if (node == nullptr) 
		return 0;

	return 1 + std::max(max_depth(node->_left),max_depth(node->_right));
}

int min_depth(BSTNode* node)
{
	if (node == nullptr) 
		return 0;

	return 1 + std::min(min_depth(node->_left),min_depth(node->_right));
}

bool IsBalanced(BSTNode* node)
{
	return ((max_depth(node) - min_depth(node)) <= 1);
}


std::vector<std::list<BSTNode*>> bfs_link(BSTNode* node)
{
	std::vector<std::list<BSTNode*>> res; 
	if (node == nullptr) return res;

	std::map<BSTNode*,size_t> d;
	d[node] = 0;

	std::list<BSTNode*> list;
	list.push_back(node);
	res.push_back(list);

	std::queue<BSTNode*> s;
	s.push(node);
	while (!s.empty()) {
		BSTNode* n = s.front(); s.pop();
		if (n->_left != nullptr) {
			d[n->_left] = d[n] + 1;
			if (d[n->_left] >= res.size()) {
				std::list<BSTNode*> n_list;
				n_list.push_back(n->_left);
				res.push_back(n_list);
			} else {
				res[d[n->_left]].push_back(n->_left);
			}
			s.push(n->_left);
		} 
		if (n->_right != nullptr) {
			d[n->_right] = d[n] + 1;
			if (d[n->_right] >= res.size()) {
				std::list<BSTNode*> n_list;
				n_list.push_back(n->_right);
				res.push_back(n_list);
			} else {
				res[d[n->_right]].push_back(n->_right);
			}
			s.push(n->_right);
		} 
	}
	return res;
}

BSTNode* CommonAncestor(BSTNode* node_a, BSTNode* node_b)
{
	if (node_a == nullptr || node_b == nullptr)
		return nullptr;
	if (node_a == node_b && node_a->_parent != nullptr)
		return node_a->_parent;
	if (node_a->_parent == nullptr)
		return node_a;
	if (node_b->_parent == nullptr)
		return node_b;

	BSTNode* a = node_a;
	BSTNode* b = node_b;
	while (a != nullptr) {
		a = a->_parent;
		b = node_b;
		while (b != nullptr && b != a)
			b = b->_parent;
		if (b != nullptr)
			return b;
	}
	return nullptr;
}

BSTNode* FindSubtree(BSTNode* node, BSTNode* in) 
{
	if (in == nullptr) 
		return nullptr;

	std::stack<BSTNode*> s;
	s.push(in);
	while	(!s.empty()) {
		BSTNode* curr = s.top();
		if (curr->_key == node->_key)
			return curr;
		s.pop();
		if (curr->_right != nullptr)
			s.push(curr->_right);
		if (curr->_left != nullptr)
			s.push(curr->_left);
	}
	return nullptr;
}

bool Match(BSTNode* node, BSTNode* with) 
{
	if (node == nullptr && with == nullptr)
		return true;
	if (node == nullptr || with == nullptr)
		return false;
	if (node->_key != with->_key)
		return false;

	return (Match(node->_left,with->_left) && Match(node->_right,with->_right));
}

int main()
{
	BST bst;
	bst.insert(5);
	bst.insert(3);
	bst.insert(7);
	bst.insert(8);
	bst.insert(9);
	bst.insert(2);
	bst.insert(6);

	if (IsBalanced(bst.get_root())) 
		std::cout << "Is balanced" << std::endl;

	std::cout << "Tree:" << std::endl;
	bst.prettyprint(bst.get_root(),0,"");
	std::cout << std::endl;

	std::cout << "BFS links:" << std::endl;
	std::vector<std::list<BSTNode*>> res = bfs_link(bst.get_root());
	for (auto l = res.begin(); l != res.end(); ++l) {
		for (auto n = (*l).begin(); n != (*l).end(); ++n) {
			std::cout << (*n)->_key << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "Common ancestor:" << std::endl;
	std::cout << CommonAncestor(bst.get_root()->_right->_left, bst.get_root()->_right->_right->_right)->_key << std::endl; 

	bst.inorder_recursive(bst.get_root());
	std::cout << std::endl;
	bst.inorder_with_stack(bst.get_root());
	std::cout << std::endl;
	bst.inorder(bst.get_root());
	std::cout << std::endl;
	
	bst.preorder_recursive(bst.get_root());
	std::cout << std::endl;
	bst.preorder_with_stack(bst.get_root());
	std::cout << std::endl;

	bst.postorder_recursive(bst.get_root());
	std::cout << std::endl;
	bst.postorder_with_stack(bst.get_root());
	std::cout << std::endl;
	
	bst.levelorder_with_stack(bst.get_root());
	std::cout << std::endl;
	
	std::cout << "min: " << bst.min(bst.get_root())
		<< " max: " << bst.max(bst.get_root()) << std::endl;

	std::cout << "succ root: " << bst.successor(bst.get_root())
		<< " pred root: " << bst.predecessor(bst.get_root()) << std::endl;

	bst.prettyprint(bst.get_root(),0,"");

	bst.remove(7);
	bst.prettyprint(bst.get_root(),0,"");
	bst.remove(3);
	bst.prettyprint(bst.get_root(),0,"");
	bst.remove(5);
	bst.prettyprint(bst.get_root(),0,"");
	bst.remove(2);
	bst.prettyprint(bst.get_root(),0,"");
}
