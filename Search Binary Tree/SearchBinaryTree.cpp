#include <iostream>
#include <sstream>

#include "SearchBinaryTree.h"
#include "NodeTree.h"


SearchBinaryTree::SearchBinaryTree()
{
	root = nullptr;
}

SearchBinaryTree::~SearchBinaryTree()
{
}

bool SearchBinaryTree::isEmpty()
{
	return (root == nullptr);
}

bool SearchBinaryTree::exists(int searchValue)
{
	return exists(root, searchValue);
}

void SearchBinaryTree::insert(int newValue)
{
	insert(root, newValue);
}

std::string SearchBinaryTree::print()
{
	std::stringstream ss;

	ss << "Preorder: " << preorder() << "\n";
	ss << "Inorder: " << inorder() << "\n";
	ss << "Postorder: " << postorder() << "\n";

	return ss.str();
}

std::string SearchBinaryTree::preorder()
{
	return preorder(root);
}

std::string SearchBinaryTree::inorder()
{
	return inorder(root);
}

std::string SearchBinaryTree::postorder()
{
	return postorder(root);
}

NodeTree* SearchBinaryTree::insertNode(int newValue)
{
	NodeTree* newNode = new NodeTree;

	newNode->data = newValue;
	newNode->left = nullptr;
	newNode->right = nullptr;

	return newNode;
}

void SearchBinaryTree::insert(NodeTree*& root, int newValue)
{
	if (isEmpty()) root = insertNode(newValue);
	else {
		if (root->data > newValue) {
			if (root->right == nullptr) root->right = insertNode(newValue);
			else insert(root->right, newValue);
		}
		if (root->data < newValue) {
			if (root->left == nullptr) root->left = insertNode(newValue);
			else insert(root->left, newValue);
		}
	}
}

bool SearchBinaryTree::exists(NodeTree* actualRoot, int searchValue)
{
	if (isEmpty()) throw std::string{ "Error: Empty Search Binary Tree.\n" };

	while (actualRoot != nullptr) {
		if (actualRoot->data == searchValue) return true;
		else (exists(actualRoot->left, searchValue) || exists(actualRoot->right, searchValue));
	}

	return false;
}

std::string SearchBinaryTree::preorder(NodeTree* root)
{
	std::stringstream ss;

	ss << root->data << preorder(root->left) << preorder(root->right);

	return ss.str();
}

std::string SearchBinaryTree::inorder(NodeTree* root)
{
	std::stringstream ss;

	ss << inorder(root->left) << root->data << inorder(root->right);

	return ss.str();
}

std::string SearchBinaryTree::postorder(NodeTree* root)
{
	std::stringstream ss;

	ss << postorder(root->left) << postorder(root->right) << root->data;

	return ss.str();
}
