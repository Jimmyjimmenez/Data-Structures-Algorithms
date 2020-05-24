#include "List.h"
#include <sstream>

List::List()
{
	start = nullptr;
	end = nullptr;
}

List::~List()
{
}

bool List::isEmpty()
{
	return (start == nullptr);
}

bool List::exists(int searchValue)
{
	if (isEmpty()) throw std::string{ "Error: Empty list.\n" };

	NodeList* actualNode = start;

	while (actualNode != nullptr) {
		if (actualNode->data == searchValue) return true;
		actualNode = actualNode->next;
	}

	return false;
}

int List::elements()
{
	NodeList* actualNode = start;
	int counter{ 0 };

	while (actualNode != nullptr) {
		counter++;
		actualNode = actualNode->next;
	}

	return counter;
}

int List::deleteStart()
{
	if (isEmpty()) throw std::string{ "Error: Empty List.\n" };

	int returnValue = start->data;	
	start = start->next;

	return returnValue;
}

int List::deleteEnd()
{
	if (isEmpty()) throw std::string{ "Error: Empty List.\n" };

	NodeList* actualNode = start;
	int returnValue{ 0 };

	while (actualNode->next != nullptr) {
		if (actualNode->next == end) {
			end = actualNode;
			actualNode->next = nullptr;
		}
		actualNode->next = actualNode;
	}

	return returnValue;
}

void List::insertStart(int imputValue)
{
	NodeList* newNode = start;
	
	newNode->data = imputValue;
	if (isEmpty()) {
		newNode->next = nullptr;
		start = newNode;
		end = newNode;
	}
	else {
		newNode->next = start;
		start = newNode;
	}

}

void List::insertEnd(int imputValue)
{
	NodeList* newNode = new NodeList;
	newNode->next = nullptr;
	newNode->data = imputValue;

	if (isEmpty()) {
		start = newNode;
		end = newNode;
	}
	else {
		end->next = newNode;
		end = newNode;
		newNode->next = nullptr;
	}
	
}

void List::deleted(int searchValue)
{
	NodeList* newNode = start;

	while (newNode != nullptr) {
		if (newNode->data = searchValue) {
			delete newNode;
			break;
		}
		newNode = newNode->next;
	}
}

std::string List::toString()
{
	std::stringstream ss;
	NodeList* actualNode = start;

	while (actualNode != nullptr) {
		ss << actualNode->data << " - ";
		actualNode = actualNode->next;
	}

	return ss.str();
}

NodeList* List::search(int)
{
	return nullptr;
}

void List::deleted(NodeList*)
{
}
