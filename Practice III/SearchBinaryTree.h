#pragma once
#include "TreeNode.h"
#include <string>

class SearchBinaryTree
{
public:

	SearchBinaryTree();
	~SearchBinaryTree();

	bool isEmpty();
	bool exists(int);

	void insert(int);

	std::string print();
	std::string preorder();
	std::string inorder();
	std::string postorder();

private:

	TreeNode* root;

	void insert(TreeNode*&, int);

	TreeNode* insertNode(int);

	bool exists(TreeNode*, int);

	std::string preorder(TreeNode*);
	std::string inorder(TreeNode*);
	std::string postorder(TreeNode*);

};

