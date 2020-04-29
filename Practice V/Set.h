#pragma once

#include <string>

class Set
{
public:

	Set(int);
	Set(int, bool);
	~Set();

	bool isEmpty() const;
	bool belongs(int);
	bool isEqual(Set);

	void insert(int);
	void deleted(int);

	static Set unites(Set, Set);
	static Set substract(Set, Set);
	static Set intersects(Set, Set);

	std::string print();

private:

	int cardinality;
	bool* elements;
};

