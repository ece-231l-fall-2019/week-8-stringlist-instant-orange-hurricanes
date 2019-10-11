#include "StringList.h"

size_t StringList::size() const noexcept
{
	size_t n = 0;
	
	for( llist *newItem = new llist;  !newItem.empty()  ; n++)
	{
		pop_back();
	}
	return n;
}

void StringList::clear() noexcept
{
	while(!empty())
	{
		pop_back();
	}		
}

std::string& StringList::back()
{
	llist newItem = new llist;
	newItem = 
	for(size_t n = size(); n != 0 ;n--)
	{	
		newItem.pop_back();
	}
	return newItem.front();
}

void StringList::push_back (std::string c);
{
	llist *newItem = new llist;
	newItem->str = _data;
	newItem->next = c;
	_data = newItem;
}

void StringList::pop_back()
{
	llist *back = _data;
	_data = back->next;
	delete back;	
}

void StringList::reserve(size_t new_cap)
{
	if( new_cap == size() )
	{
		break;
	}
	else if( new_cap > max_size())
		throw std::length_error("new_cap is greater than max_size");
	else if( new_cap > size() )
	{
		// resize
	}
	else if( new_cap < size() )
	{
		for( size_t n = size(); n != new_cap; n--, pop_back())	
	}
	else
		std::cout<< " Condition not meet " << std::endl;
}
