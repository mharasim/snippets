#ifndef __TREE_H__
#define __TREE_H__

#include <string>

struct BSTNode {
	BSTNode(int key):
		_key(key),
		_parent(nullptr), 
		_left(nullptr), 
		_right(nullptr)
	{}
	
	int _key;

	BSTNode* _parent;
	BSTNode* _left;
	BSTNode* _right;
};

class BST {
public:
	BST();
	virtual ~BST();
	
	int min(BSTNode* node);
	int max(BSTNode* node);
	
	int successor(BSTNode* node);
	int predecessor(BSTNode* node);

	void insert(int key);
	void remove(int key);
	bool search(int key);

	void inorder_recursive(BSTNode* node);
	void inorder_with_stack(BSTNode* node);
	void inorder(BSTNode* node);

	void preorder_recursive(BSTNode* node);
	void preorder_with_stack(BSTNode* node);
	
	void postorder_recursive(BSTNode* node);
	void postorder_with_stack(BSTNode* node);
	
	void levelorder_recursive(BSTNode* node);
	void levelorder_with_stack(BSTNode* node);

	BSTNode* get_root();

	void prettyprint(BSTNode* node, int indent, std::string prefix);

private:
	BSTNode* _min(BSTNode* node);
	BSTNode* _max(BSTNode* node);
	
	BSTNode* _successor(BSTNode* node);
	BSTNode* _predecessor(BSTNode* node);

	BSTNode* _search_recursive(BSTNode* node, int key);
	BSTNode* _search(BSTNode* node, int key);

	void _insert(BSTNode* node);
	void _remove(BSTNode* node);

	void _clear_recursive(BSTNode* node);
	void _clear_stack(BSTNode* node);
	void _clear();

	BSTNode* _root;

};

#endif //__TREE_H__
