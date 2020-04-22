#include <iostream>
#include "TreeAVLNode.h"
#include "AVLTree.h"

int main() {

	AVLTree newAVLTree = AVLTree();

	newAVLTree.insert(8);
	newAVLTree.insert(1);
	newAVLTree.insert(12);
	newAVLTree.insert(10);
	newAVLTree.insert(15);

	std::cout << "First AVL Tree:\n" << newAVLTree.print();

	std::cout << "\nCase 1.- Simple left rotation.\n";
	newAVLTree.insert(20);
	std::cout << newAVLTree.print();

	AVLTree secondAVLTree = AVLTree();

	secondAVLTree.insert(15);
	secondAVLTree.insert(10);
	secondAVLTree.insert(20);
	secondAVLTree.insert(5);
	secondAVLTree.insert(12);

	std::cout << "\nSecond AVL Tree:\n" << secondAVLTree.print();

	std::cout << "\nCase 2.- Simple right rotation.\n";
	secondAVLTree.insert(2);
	std::cout << secondAVLTree.print();

	AVLTree thirdAVLTree = AVLTree();

	thirdAVLTree.insert(15);
	thirdAVLTree.insert(2);
	thirdAVLTree.insert(20);
	thirdAVLTree.insert(1);
	thirdAVLTree.insert(6);
	thirdAVLTree.insert(25);
	thirdAVLTree.insert(5);
	thirdAVLTree.insert(8);

	std::cout << "\nThird AVL Tree:\n" << thirdAVLTree.print();

	std::cout << "\nCase 3.- Left-right rotation.\n";
	thirdAVLTree.insert(3);
	std::cout << thirdAVLTree.print();

	AVLTree fourthAVLTree = AVLTree();

	fourthAVLTree.insert(5);
	fourthAVLTree.insert(3);
	fourthAVLTree.insert(15);
	fourthAVLTree.insert(1);
	fourthAVLTree.insert(8);
	fourthAVLTree.insert(20);
	fourthAVLTree.insert(6);
	fourthAVLTree.insert(9);

	std::cout << "\nFourth AVL Tree:\n" << fourthAVLTree.print();

	std::cout << "\nCase 4.- Right-left rotation.\n";
	fourthAVLTree.insert(10);
	std::cout << fourthAVLTree.print();

	AVLTree fifthAVLTree = AVLTree();

	fifthAVLTree.insert(2);
	fifthAVLTree.insert(1);
	fifthAVLTree.insert(8);
	fifthAVLTree.insert(0);
	fifthAVLTree.insert(5);
	fifthAVLTree.insert(9);
	fifthAVLTree.insert(4);
	fifthAVLTree.insert(10);

	std::cout << "\nFifth AVL Tree:\n" << fifthAVLTree.print();

	return 0;
}
