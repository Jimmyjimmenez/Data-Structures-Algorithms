#include "BinaryTree.h"
#include <iostream>
#include <sstream>

BinaryTree::BinaryTree(int value, TreeNode* left, TreeNode* right)
{
	TreeNode* node = new TreeNode;

	node->data = value;
	node->left = left;
	node->right = right;

	root = node;
}

BinaryTree::~BinaryTree()
{
}

bool BinaryTree::exists(int value)
{
	return exists(root, value);
}

bool BinaryTree::isEmpty()
{
	return (root == nullptr);
}

TreeNode* BinaryTree::insertNode(TreeNode* left, TreeNode* right, int value)
{
	TreeNode* node = new TreeNode;

	node->data = value;
	node->left = left;
	node->right = right;

	return node;
}

TreeNode* BinaryTree::insert(int value)
{
	TreeNode* node = new TreeNode;

	node->data = value;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}

std::string BinaryTree::print()
{
	std::stringstream ss;

	ss << "Preorder: " << preorder(root) << "\n";
	ss << "Inorder: " << inorder(root) << "\n";
	ss << "Postorder: " << postorder(root) << "\n";

	return ss.str();
}

std::string BinaryTree::preorder()
{
	return preorder(root);
}

std::string BinaryTree::inorder()
{
	return inorder(root);
}

std::string BinaryTree::postorder()
{
	return postorder(root);
}

std::string BinaryTree::preorder(TreeNode* root)
{
	std::stringstream ss;

	if(root != nullptr) ss << root->data << " - " << preorder(root->left) << root->right;

	return ss.str();
}

std::string BinaryTree::inorder(TreeNode* root)
{
	std::stringstream ss;

	if (root != nullptr) ss << root->left << root->data << " - " << root->right;

	return ss.str();
}

std::string BinaryTree::postorder(TreeNode* root)
{
	std::stringstream ss;

	if (root != nullptr) ss << postorder(root->left) << postorder(root->right) << root->data << " - ";

	return ss.str();
}

bool BinaryTree::exists(TreeNode* root, int value)
{
	if (isEmpty()) throw std::string{ "Error: The tree is empty.\n" };
	if (root->data == value) return true;
	else exists(root->left, value) || exists(root->right, value);
	return false;
}


