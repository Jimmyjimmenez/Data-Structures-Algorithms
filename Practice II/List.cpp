#include "List.h"
#include <sstream>


List::List()
{
}

List::~List()
{

}

bool List::isEmpty()
{
	return start == nullptr;
}

bool List::exists(int value)
{
	ListNode* actualNode = start;

	while (actualNode->next != nullptr) {
		if (actualNode->data == value) return true;
		actualNode = actualNode->next;
	}
	return false;
}

int List::elements()
{
	ListNode* actualNode = start;
	int cont{ 0 };
	while (actualNode != nullptr) {
		cont++;
		actualNode = actualNode->next;
	}
	return cont;
}

int List::deleteStart()
{
	if (isEmpty()) throw std::string{ "Error: Empty list.\n" };
	int returnValue = start->data;
	start = start->next;
	return returnValue;
}

int List::deleteEnd()
{
	if (isEmpty()) throw std::string{ "Error: Empty list.\n" };
	ListNode* actualNode = start;
	int returnValue = end->data;
	
	while (actualNode->next != nullptr) {
		if (actualNode->next == end) {
			end = actualNode;
			actualNode->next = nullptr;
		}
		actualNode = actualNode->next;
	}
	return returnValue;
}

void List::insertStart(int value)
{
	ListNode* newNode = new ListNode;
	newNode->data = value;

	if(isEmpty()) {
		newNode->next = nullptr;
		start = newNode;
		end = newNode;
	}
	else {
		newNode->next = start;
		start = newNode;
	}
}

void List::insertEnd(int value)
{
	ListNode* newNode = new ListNode;
	newNode->data = value;
	newNode->next = nullptr;

	if (isEmpty()) {
		end = newNode;
		start = newNode;
	}
	else {
		end->next = newNode;
		end = newNode;
	}
}

std::string List::toString()
{
	std::stringstream ss;
	if (isEmpty()) throw std::string{ "Error: Empty list.\n" };

	ListNode* actualNode = start;
	while (actualNode != nullptr) {
		ss << actualNode->data << " - ";
		actualNode = actualNode->next;
	}

	return ss.str();
}
