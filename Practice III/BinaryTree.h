#pragma once
#include <string>
#include "TreeNode.h"

class BinaryTree
{
public:

	BinaryTree(int, TreeNode*, TreeNode*);
	~BinaryTree();

	bool exists(int);
	bool isEmpty();

	static TreeNode* insertNode(TreeNode*, TreeNode*, int);
	static TreeNode* insert(int);

	std::string print();
	std::string preorder();
	std::string inorder();
	std::string postorder();

private:
	TreeNode* root;

	std::string preorder(TreeNode*);
	std::string inorder(TreeNode*);
	std::string postorder(TreeNode*);

	bool exists(TreeNode*, int);
};

