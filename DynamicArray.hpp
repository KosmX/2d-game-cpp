#pragma once

#include <list>

//I won't be able to do an enhanced (Range-based) for with this...


//Dynamic data type, set (not ordered), I'll use arrays for entry pointers, I will leave nullptr in the list.
//I don't want to waste time with resizing this, I'll allocate more memory and if I delete from this, I'll do it in
/**
 * @brief Dynamic array, to store entities, have a buffer, to don't tick newly added entities too early
 */
template<typename T>
class DynamicArray
{
private:
	//I won't be very efficient
	std::list<T> entries;
	std::list<T> newEntries;

public:
	DynamicArray() : entries(), newEntries(){}

	DynamicArray<T>& operator+=(T& entry)
	{
		newEntries.push_back(entry);
		return *this;
	}

	/**
	 * @return an iterator pointing to the first, newly added element.
	 */
	auto finalizeAdd()
	{
		//this moves every entry form newEntries to entries.
		//makes the newEntries empty.
		//entries.merge(newEntries); merge needs two ordered lists, i have only sets.
		auto oldEnd = newEntries.begin() != newEntries.end() ? newEntries.begin() : entries.end();
		entries.splice(entries.end(), newEntries);
		return oldEnd;
	}

	void removeIf(bool (*l)(const T&))
	{
		entries.remove_if(l);
	}
	
	//It will mainly iterate, not search
	auto begin()
	{
		return entries.begin();
	}
	auto end()
	{
		return entries.end();
	}
	int getSize() const
	{
		return entries.size();
	}
};
