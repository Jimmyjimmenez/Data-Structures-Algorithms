#include <iostream>
#include <sstream>
#include "AVLTree.h"

AVLTree::AVLTree()
{
}

AVLTree::~AVLTree()
{
}

void AVLTree::insert(int value)
{
	insert(root, value);
}

void AVLTree::leftrotation(TreeAVLNode*& root)
{
	TreeAVLNode* node = new TreeAVLNode;
	TreeAVLNode* aux = new TreeAVLNode;

	node = root->left->right;
	root->left->right = root;
	root->left->equilibrium = 0;
	aux = root->left;
	root->left = node;
	root->equilibrium = 0;
	root = aux;
}

void AVLTree::rightrotation(TreeAVLNode*& root)
{
	TreeAVLNode* node = new TreeAVLNode;
	TreeAVLNode* aux = new TreeAVLNode;

	node = root->right->left;
	root->right->left = root;
	root->right->equilibrium = 0;
	aux = root->right;
	root->right = node;
	root->equilibrium = 0;
	root = aux;
}

void AVLTree::autobalance(TreeAVLNode*& root)
{
	if (root->equilibrium == 2) {
		if (root->right->equilibrium < 0) {
			rightrotation(root->right);
			leftrotation(root);
		}
		else leftrotation(root);
	}
	else if (root->equilibrium == -2) {
		if (root->left->equilibrium > 0) {
			leftrotation(root->left);
			rightrotation(root);
		}
		else rightrotation(root);
	}
}

int AVLTree::maximun(int a, int b)
{
	return (a >= b) ? a : b;
}

int AVLTree::height()
{
	return height(root);
}

int AVLTree::equilibrium(TreeAVLNode* root)
{
	return (height(root->right) - height(root->left));
}

bool AVLTree::isEmpty()
{
	return (root == nullptr);
}

bool AVLTree::exists(int value)
{
	return exists(root, value);
}

std::string AVLTree::preorder()
{
	return preorder(root);
}

std::string AVLTree::inorder()
{
	return inorder(root);
}

std::string AVLTree::postorder()
{
	return postorder(root);
}

std::string AVLTree::print()
{
	std::stringstream ss;

	ss << "Preorder: " << preorder(root);
	ss << "Inorder: " << inorder(root);
	ss << "Postorder: " << postorder(root);
	return ss.str();
}

int AVLTree::height(TreeAVLNode* root)
{
	return ((root == nullptr) ? -1 : maximun(height(root->left), height(root->right)) + 1);
}

void AVLTree::insert(TreeAVLNode*& root, int value)
{
	if (isEmpty()) root = insertNode(value);
	else {
		if (value < root->data) {
			if (root->left == nullptr) root->left = insertNode(value);
			else insert(root->left, value);
		}
		if (value > root->data) {
			if (root->right == nullptr) root->right = insertNode(value);
			else insert(root->right, value);
		}
	}
	root->height = height(root);
	root->equilibrium = equilibrium(root);
	if (abs(root->equilibrium) > 1) autobalance(root);
}

bool AVLTree::exists(TreeAVLNode* root, int value)
{
	if (root != nullptr) {
		if (root->data = value) return true;
		exists(root->left, value) || exists(root->right, value);
	}
	return false;
}

TreeAVLNode* AVLTree::insertNode(int value)
{
	TreeAVLNode* node = new TreeAVLNode;

	node->data = value;
	node->equilibrium = 0;
	node->height = height(root);
	node->left = nullptr;
	node->right = nullptr;
	
	return node;
}

std::string AVLTree::preorder(TreeAVLNode* root)
{
	std::stringstream ss;

	if (root != nullptr) {
		ss << root->data << preorder(root->left) << preorder(root->right) << "\n";
	}
	return ss.str();
}

std::string AVLTree::inorder(TreeAVLNode* root)
{
	std::stringstream ss;

	if (root != nullptr) {
		ss << inorder(root->left) << root->data << preorder(root->right) << "\n";
	}
	return ss.str();
}

std::string AVLTree::postorder(TreeAVLNode* root)
{
	std::stringstream ss;

	if (root != nullptr) {
		ss << postorder(root->left) << postorder(root->right) << root->data << "\n";
	}
	return ss.str();
}
