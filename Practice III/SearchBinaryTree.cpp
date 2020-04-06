#include "SearchBinaryTree.h"
#include <sstream>

SearchBinaryTree::SearchBinaryTree()
{
}

SearchBinaryTree::~SearchBinaryTree()
{
}

bool SearchBinaryTree::isEmpty()
{
	return (root == nullptr);
}

bool SearchBinaryTree::exists(int value)
{
	if (root != nullptr) {
		if (root->data == value) return true;
		return exists(root->left, value) || exists(root->right, value);
	}
	return false;
}

void SearchBinaryTree::insert(int value)
{
	insert(root, value);
}

std::string SearchBinaryTree::print()
{
	std::stringstream ss;

	ss << "Preorder: " << preorder(root) << "\n";
	ss << "Inorder: " << inorder(root) << "\n";
	ss << "Postorder: " << postorder(root) << "\n";

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

void SearchBinaryTree::insert(TreeNode*& root, int value)
{
	if (isEmpty()) root = insertNode(value);
	else {
		if (root->data > value) {
			if (root->left == nullptr) root->left = insertNode(value);
			else insert(root->left, value);
		}
		else if (root->data < value) {
			if (root->right == nullptr) root->right = insertNode(value);
			else insert(root->right, value);
		}
	}
}

TreeNode* SearchBinaryTree::insertNode(int value)
{
	TreeNode* node = new TreeNode;

	node->data = value;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}

bool SearchBinaryTree::exists(TreeNode* root, int value)
{
	return exists(value);
}

std::string SearchBinaryTree::preorder(TreeNode* root)
{
	std::stringstream ss;

	if (root != nullptr) ss <<  root->data << " - " << preorder(root->left) << preorder(root->right);
	
	return ss.str();
}

std::string SearchBinaryTree::inorder(TreeNode* root)
{
	std::stringstream ss;

	if (root != nullptr) ss << inorder(root->left) << root->data << " - " << inorder(root->right);

	return ss.str();
}

std::string SearchBinaryTree::postorder(TreeNode* root)
{
	std::stringstream ss;

	if (root != nullptr) ss << postorder(root->left) << postorder(root->right) << root->data << " - ";

	return ss.str();
}
