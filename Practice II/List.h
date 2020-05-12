#pragma once
#include <string>

#include "ListNode.h"

class List
{
public:

	List();
	~List();

	bool isEmpty();
	bool exists(int);

	int elements();
	int deleteStart();
	int deleteEnd();

	void insertStart(int);
	void insertEnd(int);

	std::string toString();

private:

	ListNode* start, * end;
	ListNode* search(int);

	void deleted(ListNode*);
};

