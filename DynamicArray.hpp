#pragma once

#include <list>
#include <vector>

//I won't be able to do an enhanced (Range-based) for with this...


//Dynamic data type, set (not ordered), I'll use arrays for entry pointers, I will leave nullptr in the list.
//I don't want to waste time with resizing this, I'll allocate more memory and if I delete from this, I'll do it in
template<typename T>
class DynamicArray
{
private:
	std::vector<T> entries;
	std::list<T> newEntries;

public:
	
	auto begin()
	{
		return entries.begin();
	}
};

