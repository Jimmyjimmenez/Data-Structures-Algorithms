#pragma once
#include <iostream>
#include <string>

#include "NodeList.h"

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
	void deleted(int);
	
	std::string toString();

private:

	NodeList* start;
	NodeList* end;
	NodeList* search(int);

	void deleted(NodeList*);


};

