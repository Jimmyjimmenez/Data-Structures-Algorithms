#include <iostream>
#include "TreeAVLNode.h"
#include "AVLTree.h"
#include "MinimumHeaps.h"

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

	fifthAVLTree.deleted(4);
	std::cout << "\nDeleted node 4\n";
	std::cout << fifthAVLTree.print();

	fifthAVLTree.deleted(9);
	std::cout << "\nDeleted node 9\n";
	std::cout << fifthAVLTree.print();

	fifthAVLTree.deleted(2);
	std::cout << "\nDeleted node 2 \n";
	std::cout << fifthAVLTree.print();

	fifthAVLTree.deleted(0);
	std::cout << "\nDeleted node 0 \n";
	std::cout << fifthAVLTree.print();

	fifthAVLTree.deleted(1);
	std::cout << "\nDeleted node 1 \n";
	std::cout << fifthAVLTree.print();

	std::cout << "\nMinimum Mounds:\n";

	MinimumHeaps newMinimumHeaps = MinimumHeaps(50);

	newMinimumHeaps.insert(4);
	newMinimumHeaps.insert(5);
	newMinimumHeaps.insert(6);
	newMinimumHeaps.insert(3);
	newMinimumHeaps.insert(11);
	newMinimumHeaps.insert(7);
	newMinimumHeaps.insert(9);
	newMinimumHeaps.insert(14);
	newMinimumHeaps.insert(10);
	newMinimumHeaps.insert(8);

	std::cout << newMinimumHeaps.print();
	std::cout << "\nInsert 2.\n";
	newMinimumHeaps.insert(2);
	std::cout << newMinimumHeaps.print();

	int min = newMinimumHeaps.deletedMinimum();

	std::cout << "\nMinimum eliminated: " << min << "\n" << newMinimumHeaps.print();

	min = newMinimumHeaps.deletedMinimum();

	std::cout << "\nMinimum eliminated: " << min << "\n" << newMinimumHeaps.print();
	return 0;
}
