#include <iostream>
#include <sstream>
#include "BinaryTree.h"
#include "SearchBinaryTree.h"

int main() {

	std::cout << "Binary Tree:\n";

	TreeNode* node1 = BinaryTree::insert(20);
	TreeNode* node2 = BinaryTree::insert(30);
	TreeNode* node3 = BinaryTree::insertNode(node1, node2, 10);

	TreeNode* node4 = BinaryTree::insert(50);
	TreeNode* node5 = BinaryTree::insert(60);
	TreeNode* node6 = BinaryTree::insertNode(node4, node5, 40);

	BinaryTree bt = BinaryTree(70, node3, node6);

	std::cout << bt.print() << "\n-------------";
	
	std::cout << "\nSearch Binary Tree:\n";

	SearchBinaryTree sbt = SearchBinaryTree();

	sbt.insert(10);
	sbt.insert(30);
	sbt.insert(20);
	sbt.insert(40);

	std::cout << sbt.print();

	return 0;
}