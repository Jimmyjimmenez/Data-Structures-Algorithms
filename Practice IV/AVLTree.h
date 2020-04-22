#pragma once
#include "TreeAVLNode.h"
#include <string>

class AVLTree
{
public:

	AVLTree();
	~AVLTree();

	void insert(int);
	void deleted(int);
	
	int height();

	bool isEmpty();
	bool exists(int);

	std::string preorder();
	std::string inorder();
	std::string postorder();
	std::string print();

private:
	TreeAVLNode* root;

	int height(TreeAVLNode*);
	int maximun(int, int);
	int equilibrium(TreeAVLNode*);
	int deleteMinimun(TreeAVLNode*&);

	void insert(TreeAVLNode*&, int);
	void leftRotation(TreeAVLNode*&);
	void rightRotation(TreeAVLNode*&);
	void autobalance(TreeAVLNode*&);
	void deleted(TreeAVLNode*&, int);

	bool exists(TreeAVLNode*, int);

	TreeAVLNode* insertNode(int);
	TreeAVLNode* minimun(TreeAVLNode*);
	TreeAVLNode* maximun(TreeAVLNode*);

	std::string preorder(TreeAVLNode*);
	std::string inorder(TreeAVLNode*);
	std::string postorder(TreeAVLNode*);
};

