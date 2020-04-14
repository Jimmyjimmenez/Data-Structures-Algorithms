#pragma once
#include "TreeAVLNode.h"
#include <string>

class AVLTree
{
public:

	AVLTree();
	~AVLTree();

	void insert(int);
	void leftrotation(TreeAVLNode*&);
	void rightrotation(TreeAVLNode*&);
	void autobalance(TreeAVLNode*&);

	int maximun(int, int);
	int height();
	int equilibrium(TreeAVLNode*);

	bool isEmpty();
	bool exists(int);

	std::string preorder();
	std::string inorder();
	std::string postorder();
	std::string print();

private:
	TreeAVLNode* root;

	int height(TreeAVLNode*);

	void insert(TreeAVLNode*&, int);

	bool exists(TreeAVLNode*, int);

	TreeAVLNode* insertNode(int);

	std::string preorder(TreeAVLNode*);
	std::string inorder(TreeAVLNode*);
	std::string postorder(TreeAVLNode*);
};

