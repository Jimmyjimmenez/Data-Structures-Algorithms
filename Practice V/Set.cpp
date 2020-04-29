#include "Set.h"
#include <sstream>

Set::Set(int set)
{
	cardinality = set;
	elements = new bool[cardinality];

	for (int i{ 0 }; i < cardinality; i++) elements[i] = false;
}

Set::Set(int set, bool belongs)
{
	cardinality = set;
	elements = new bool[cardinality];

	for (int i{ 0 }; i < cardinality; i++) elements[i] = belongs;
}

Set::~Set()
{
	delete[] elements;
}

bool Set::isEmpty() const
{
	bool isEmpty = true;

	for (int i{ 0 }; i < cardinality; i++) {
		if (elements[i]) {
			isEmpty = false;
			break;
		}
	}
}

bool Set::belongs(int exists)
{
	bool exists;

	if (exists >= 1 && exists <= cardinality) exists = elements[exists - 1];
	else exists = false;
	return exists;
}

bool Set::isEqual(Set actualSet)
{
	bool isEqual;

	if (actualSet.cardinality == cardinality) {
		isEqual = true;

		for (int i{ 0 }; i < actualSet.cardinality; i++) {
			if (actualSet.elements[i] != elements[i]) {
				isEqual = false;
				break;
			}
		}
	}
	else isEqual = false;

	return isEqual;
}

void Set::insert(int exists)
{
	if (exists >= 1 && exists <= cardinality) elements[exists - 1] = true;
}

void Set::deleted(int exists)
{
	if (exists >= 1 && exists <= cardinality) elements[exists - 1] = false;
}

Set Set::unites(Set actualSet, Set nextSet)
{
	Set returnSet = Set(actualSet.cardinality);

	if (actualSet.cardinality == nextSet.cardinality) {
		for (int i{ 0 }; i <= actualSet.cardinality; i++) {
			if (actualSet.belongs(i) || nextSet.belongs(i)) returnSet.insert(i);
		}
	}

	return returnSet;
}

Set Set::substract(Set actualSet, Set nextSet)
{
	Set returnSet = Set(actualSet.cardinality);

	if (actualSet.cardinality == nextSet.cardinality) {
		for (int i{ 0 }; i <= actualSet.cardinality; i++) {
			if (actualSet.belongs(i) && !actualSet.belongs(i)) returnSet.insert(i);
		}
	}

	return returnSet;
}

Set Set::intersects(Set actualSet, Set nextSet)
{
	Set returnSet = Set(actualSet.cardinality);

	if (actualSet.cardinality == nextSet.cardinality) {
		for (int i{ 0 }; i <= actualSet.cardinality; i++) {
			if (actualSet.belongs(i) && nextSet.belongs(i)) returnSet.insert(i);
		}
	}
	return returnSet;
}

std::string Set::print()
{
	std::stringstream ss;

	for (int i{ 0 }; i < cardinality; i++) {
		if (elements[i]) ss << " " << (i + 1);
	}

	return ss.str();
}
