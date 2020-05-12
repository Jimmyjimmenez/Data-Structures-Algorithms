#include <iostream>

#include "List.h"

int main() {

	List newList;

	newList.insertStart(20);
	newList.insertEnd(30);
	newList.insertStart(10);

	std::cout << "Data: " << newList.toString() << "\n";
	std::cout << "Elements: " << newList.elements();
	return 0;
}