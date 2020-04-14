#include <iostream>
#include "TreeAVLNode.h"
#include "AVLTree.h"

int main() {

	AVLTree* newAVLTree = new AVLTree();

	newAVLTree->insert(20);
	newAVLTree->insert(30);
	newAVLTree->insert(40);

	newAVLTree->print();
	return 0;
}