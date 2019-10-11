#include "StringList.h"

size_t StringList::size() const
{ 
	size_t n = 0;
	llist *Copy = new llist;
	Copy = _data;
	for( llist *temp = Copy; Copy->next == NULL; n++)
	{
		temp = Copy->next;
		Copy = temp->next;
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
	while( _data->next != NULL )
	{
		llist *tail = _data;
		tail = _data->next;
		_data = tail;
		if( _data->next == NULL )
		{
			return _data->str;
		}
	}	
	return _data->str;
}

void StringList::push_back (std::string c)
{
	llist *temp = _data;
	while( _data->next != NULL )
	{
		temp = _data->next;
		_data = temp;
		if( _data->next == NULL )
		{
			_data->str = c;
		}
	}
	_data->str = c;
}

void StringList::pop_back()
{
	llist *back = _data;
	while( _data->next != NULL )
	{
		back = _data->next;
		if( back->next == NULL)
		{
			delete back;
		}
		_data = back;
	}
	
	delete back;	
}

void StringList::reserve(size_t new_cap)
{	

	if( new_cap == size() )
		return;	

/*	else if( new_cap > max_size())
		throw std::length_error("new_cap is greater than max_size");
*/
	else if( new_cap > size() )
	{
		llist *add_node = _data;
		while( _data->next != 0)
		{
			add_node = _data->next;
			_data = add_node;
			if( _data->next == NULL)
			{
				for( size_t n = size(); n != 0; n-- )
				{
					_data = add_node->next;
					add_node = _data;
				}
			}	 
		}
	}
	else if( new_cap < size() )
	{
		for( size_t n = size(); n != new_cap; n--)
			pop_back();	
	}
	else
		std::cout<< " Condition not meet " << std::endl;
}
