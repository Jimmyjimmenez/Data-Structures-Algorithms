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

void AVLTree::deleted(int value)
{
	deleted(root, value);
}

void AVLTree::leftRotation(TreeAVLNode*& root)
{
	TreeAVLNode* node;

	node = root->right;
	root->right = node->left;
	node->left = root;

	root->height = height(root);
	root->equilibrium = equilibrium(root);

	node->height = height(node);
	node->equilibrium = equilibrium(node);

	if (this->root == root) this->root = node;
	else root = node;
}

void AVLTree::rightRotation(TreeAVLNode*& root)
{
	TreeAVLNode* node = new TreeAVLNode;
	
	node = root->left;
	root->left = node->right;
	node->right = root;

	root->height = height(root);
	root->equilibrium = equilibrium(root);

	node->height = height(node);
	node->equilibrium = equilibrium(node);

	if (this->root == root) this->root = node;
	else root = node;
}

void AVLTree::autobalance(TreeAVLNode*& root)
{
	if (root->equilibrium == 2) {
		leftRotation(root);
	}
	else if (root->equilibrium == -2) {
		rightRotation(root);
	}
}

void AVLTree::deleted(TreeAVLNode*& root, int value)
{
	if (isEmpty()) std::string{ "Error: AVL Tree empty.\n " };
	else {
		if (value == root->data) {
			delete root;
		}
		else if (root->left != nullptr) deleted(root->left, value);
		else deleted(root->right, value);
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

int AVLTree::deleteMinimun(TreeAVLNode*& root)
{
	
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

	ss << "Preorder: " << preorder(root) << "\n";
	ss << "Inorder: " << inorder(root) << "\n";
	ss << "Postorder: " << postorder(root) << "\n";
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
		ss << root->data << " - " << preorder(root->left) << preorder(root->right);
	}
	return ss.str();
}

std::string AVLTree::inorder(TreeAVLNode* root)
{
	std::stringstream ss;

	if (root != nullptr) {
		ss << inorder(root->left) << root->data << " - " << preorder(root->right);
	}
	return ss.str();
}

std::string AVLTree::postorder(TreeAVLNode* root)
{
	std::stringstream ss;

	if (root != nullptr) {
		ss << postorder(root->left) << postorder(root->right) << root->data << " - ";
	}
	return ss.str();
}
