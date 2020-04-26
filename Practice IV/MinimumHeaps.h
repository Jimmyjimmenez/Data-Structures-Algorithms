#pragma once

#include <iostream>

class MinimumHeaps
{
public:

	MinimumHeaps(int);
	~MinimumHeaps();

	bool isEmpty();

	void insert(int);

	int deletedMinimum();

	std::string print();

private:

	bool minimum(int&);

	void exchange(int, int);
	void ascendentExchange(int, int);
	void descendentExchange(int);

	int last;
	int capacity;
	int* priority;
};

