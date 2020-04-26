#include "MinimumHeaps.h"
#include <sstream>

MinimumHeaps::MinimumHeaps(int value)
{
	if (value <= 0) throw std::runtime_error{ "Size of the heap not valid.\n" };

	last = -1;
	capacity = value;
	priority = new int[capacity];
}

MinimumHeaps::~MinimumHeaps()
{
	delete priority;
}

bool MinimumHeaps::isEmpty()
{
	return (last < 0);
}

void MinimumHeaps::insert(int value)
{
	if (last == capacity - 1) throw std::runtime_error{ "Full heap\n" };

	last++;
	priority[last] = value;
	ascendentExchange((last - 1) / 2, last);
}

int MinimumHeaps::deletedMinimum()
{
	if (isEmpty()) throw std::runtime_error{ "Empty heap.\n" };

	int minimum = priority[0];
	priority[0] = priority[last--];
	descendentExchange(0);

	return minimum;
}

std::string MinimumHeaps::print()
{
	std::stringstream ss;

	for (int i{ 0 }; i <= last; i++) {
		ss << priority[i] << " - ";
	}

	return ss.str();
}

bool MinimumHeaps::minimum(int& value)
{
	if (isEmpty()) return false;
	value = priority[0];
	return true;
}

void MinimumHeaps::exchange(int first, int last)
{
	int value = priority[first];
	priority[first] = priority[last];
	priority[last] = value;
}

void MinimumHeaps::ascendentExchange(int father, int son)
{
	if (priority[son] < priority[father]) exchange(father, son);
	if (father != 0) ascendentExchange((father - 1) / 2, father);
}

void MinimumHeaps::descendentExchange(int father)
{
	int left = 2 * father + 1, right = 2 * father + 2;

	if (left <= last) {
		if (right <= last) {
			if (priority[left] < priority[right]) {
				if (priority[father] > priority[left]) {
					exchange(father, left);
					descendentExchange(left);
				}
			}
			else {
				if (priority[father] > priority[right]) {
					exchange(father, right);
					descendentExchange(right);
				}
			}
		} else {
			if (priority[father] > priority[left]) {
				exchange(father, left);
				descendentExchange(left);
			}
		}
	}
}
