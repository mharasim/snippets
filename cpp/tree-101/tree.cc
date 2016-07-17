#include "tree.h"

#include <stack>
#include <queue>
#include <iostream>
#include <iomanip>


BST::BST():
	_root(nullptr)
{}

BST::~BST()
{ _clear_recursive(_root);
	//_clear_stack(_root);
}

int BST::min(BSTNode* node)
{ return _min(node)->_key; }

int BST::max(BSTNode* node)
{ return _max(node)->_key; }
	
int BST::successor(BSTNode* node)
{ return _successor(node)->_key; }

int BST::predecessor(BSTNode* node)
{ return _predecessor(node)->_key; }

void BST::_insert(BSTNode* node)
{
	if (node == nullptr) return;

	BSTNode* insert_node = nullptr;
	BSTNode* search_node = _root;
	
	while (search_node != nullptr) {
		insert_node = search_node;
		if (node->_key < search_node->_key)
			search_node = search_node->_left;
		else
			search_node = search_node->_right;
	}
	
	node->_parent = insert_node;

	if (insert_node == nullptr) {
		_root = node;
		return;
	}
	
	if (node->_key < insert_node->_key)
		insert_node->_left = node;
	else
		insert_node->_right = node;
}

void BST::insert(int key)
{
	_insert(new BSTNode(key));	
}

void BST::_remove(BSTNode* node)
{
	BSTNode* to_remove = nullptr;
	BSTNode* orphaned = nullptr;

	// If node has one child we can remove it,
	// Else we have to swap it for successor key
	// and remove it from there
	if (node->_left == nullptr || node->_right == nullptr)
		to_remove = node;
	else
		to_remove = _successor(node);

	// Find node that will by orphaned by removal
	if (to_remove->_left != nullptr)
		orphaned = to_remove->_left;
	else
		orphaned = to_remove->_right;
	
	// If there is orphan - reparent
	if (orphaned != nullptr)
		orphaned->_parent = to_remove->_parent;

	// Orphan the node that has to be removed
	// SPECIAL: look out for root!
	if (to_remove->_parent == nullptr)
		_root = orphaned;
	else {
		if (to_remove->_parent->_left == to_remove)
			to_remove->_parent->_left = orphaned;
		else 
			to_remove->_parent->_right = orphaned;
	}
	// If node had two children find some pease
	// in allowing successor key to live in its
	// body.
	if (node != to_remove)
		node->_key = to_remove->_key;

	// R.I.P
	delete to_remove;
}

void BST::remove(int key)
{ BSTNode* node = _search(_root, key);
	if (node != nullptr) _remove(node); 
}

bool BST::search(int key)
{ return (_search(_root, key) != nullptr); 
}

void BST::inorder_recursive(BSTNode* node)
{
	if (node == nullptr) return;
	
	inorder_recursive(node->_left);
	
	// visit
	std::cout << node->_key << ";";
	
	inorder_recursive(node->_right);
}

void BST::inorder_with_stack(BSTNode* node)
{
	std::stack<BSTNode*> nodes_visited;
	BSTNode* visited = node;

	while (!nodes_visited.empty() || visited != nullptr) {
		if (visited != nullptr) {
			nodes_visited.push(visited);
			visited = visited->_left;
		} else {
			visited = nodes_visited.top(); nodes_visited.pop();
			std::cout << visited->_key << ";" ;
			visited = visited->_right;
		}
	}

}

// Inorder withour stack and recursion (Morris threaded traversal)
void BST::inorder(BSTNode* node)
{
	BSTNode* curr = node;
	BSTNode* pred = nullptr;

	while (curr != nullptr) {
		
		if (curr->_left == nullptr) {

			// Print and go right ("normal" right or thread)
			std::cout << curr->_key << ";" ;
			curr = curr->_right;

		} else {

			// We will have to return here so go find inorder predeccessor 
			// and thread it here 
			
			pred = curr->_left;
			// Stop if predeccessor found or thread already exists
			while (pred->_right != nullptr && pred->_right != curr)
				pred = pred->_right;
			
			if (pred->_right == nullptr) {
				// Create thread to current and go further left
				pred->_right = curr;
				curr = curr->_left;
			} else {
				// Finished - break thread and continue right
				pred->_right = nullptr;
				std::cout << curr->_key << ";" ;
				curr = curr->_right;
			}
		}
	}
}

void BST::preorder_recursive(BSTNode* node)
{
	if (node == nullptr) return;
	
	// visit
	std::cout << node->_key << ";" ;

	preorder_recursive(node->_left);
	
	preorder_recursive(node->_right);

}

void BST::preorder_with_stack(BSTNode* node)
{
	std::stack<BSTNode*> nodes_visited;
	BSTNode* visited = node;

	while (!nodes_visited.empty() || visited != nullptr) {
		if (visited != nullptr) {
			std::cout << visited->_key << ";" ;
			if (visited->_right != nullptr) 
				nodes_visited.push(visited->_right);
			visited = visited->_left;
		} else {
			visited = nodes_visited.top(); nodes_visited.pop();
		}
	}

}


void BST::postorder_recursive(BSTNode* node)
{
	if (node == nullptr) return;

	postorder_recursive(node->_left);
	
	postorder_recursive(node->_right);

	// visit
	std::cout << node->_key << ";" ;
}

void BST::postorder_with_stack(BSTNode* node)
{
		std::stack<BSTNode*> nodes_visited;
		BSTNode* visited = node;
		BSTNode* last_visited = nullptr;

		while (!nodes_visited.empty() || visited != nullptr) {
			if (visited != nullptr) {
				nodes_visited.push(visited);
				visited = visited->_left;
			} else {
				BSTNode* peeked = nodes_visited.top();
				if (peeked->_right != nullptr && last_visited != peeked->_right)
					visited = peeked->_right;
				else {
					std::cout << peeked->_key << ";" ;
					last_visited = peeked; nodes_visited.pop();
				}
			}
		}
}

void BST::levelorder_recursive(BSTNode* node)
{}

void BST::levelorder_with_stack(BSTNode* node)
{
	if (node == nullptr) return;

	std::queue<BSTNode*> nodes_visited;
	nodes_visited.push(node);
	BSTNode* visited = nullptr;

	while (!nodes_visited.empty()) {
		visited = nodes_visited.front(); nodes_visited.pop();
		std::cout << visited->_key << ";" ;
		if (visited->_left != nullptr)
			nodes_visited.push(visited->_left);
		if (visited->_right != nullptr)
			nodes_visited.push(visited->_right);
	}
}

BSTNode* BST::get_root()
{ return _root;
}

void BST::prettyprint(BSTNode* node, int indent, std::string prefix)
{
	if (node == nullptr) return;

	if (indent > 0) 
		std::cout << std::setw(indent) << ' ';
	std::cout << prefix << node->_key << "\n ";

	if (node->_right != nullptr) prettyprint(node->_right, indent+4, "/ ");
	if (node->_left != nullptr) prettyprint(node->_left, indent+4, "\\ ") ; 
}

BSTNode* BST::_min(BSTNode* node)
{
	BSTNode* search_node = node;
	while (search_node->_left != nullptr)
		search_node = search_node->_left;
	return search_node;
}

BSTNode* BST::_max(BSTNode* node)
{
	BSTNode* search_node = node;
	while (search_node->_right != nullptr)
		search_node = search_node->_right;
	return search_node;
}

BSTNode* BST::_successor(BSTNode* node)
{
	if (node == nullptr) return node;
	if (node->_right != nullptr)
		return _min(node->_right);

	// Go up until nullptr or parent exits from left subtree
	BSTNode* parent_node = node->_parent;
	BSTNode* search_node = node;
	while (parent_node != nullptr && search_node == parent_node->_right) {
		search_node = parent_node;
		parent_node = parent_node->_parent;
	}

	return parent_node;
}
	
BSTNode* BST::_predecessor(BSTNode* node)
{
	if (node == nullptr) return node;
	if (node->_left != nullptr)
		return _max(node->_left);

	// Go up until nullptr or parent exits from right subtree
	BSTNode* parent_node = node->_parent;
	BSTNode* search_node = node;
	while (parent_node != nullptr && search_node == parent_node->_left) {
		search_node = parent_node;
		parent_node = parent_node->_parent;
	}

	return parent_node;
}

BSTNode* BST::_search_recursive(BSTNode* node, int key)
{
	if (node == nullptr || node->_key == key)
		return node;
	
	if (key < node->_key)
		return _search_recursive(node->_left, key);
	else
		return _search_recursive(node->_right, key);
}

BSTNode* BST::_search(BSTNode* node, int key)
{
	BSTNode* search_node = node;
	while (search_node != nullptr && search_node->_key != key) {
		if (key < search_node->_key) 
			search_node = search_node->_left;
		else
			search_node = search_node->_right;
	}
	return search_node;
}

void BST::_clear_recursive(BSTNode* node)
{
	if (node == nullptr) return;

	if (node->_left != nullptr)
		_clear_recursive(node->_left);
	if (node->_right != nullptr)
		_clear_recursive(node->_right);

	node->_parent = nullptr;
	delete node;
}

void BST::_clear_stack(BSTNode* node)
{
	if (node == nullptr) return;

	std::stack<BSTNode*> nodes_visited;
	nodes_visited.push(node);

	while (!nodes_visited.empty()) {
		BSTNode* current = nodes_visited.top();
		if (current->_left == nullptr && current->_right == nullptr) {
			nodes_visited.pop();
			delete current;
		} else {
			if (current->_left != nullptr)
				nodes_visited.push(current->_left);
			if (current->_right != nullptr)
				nodes_visited.push(current->_right);
		}
	}
}
	
void BST::_clear()
{}



