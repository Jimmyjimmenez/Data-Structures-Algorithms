#pragma once
#include <string>

#include "NodeTree.h"
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

	NodeTree* root;
	NodeTree* insertNode(int);

	void insert(NodeTree*&, int);

	bool exists(NodeTree*, int);

	std::string preorder(NodeTree*);
	std::string inorder(NodeTree*);
	std::string postorder(NodeTree*);

};

