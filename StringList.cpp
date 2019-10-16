#include "StringList.h"


/*
basic_string& operator=( basic_string&& str );
{
	// Reminder: Op= Its wrong! Add prev to all functions 

	llist *new = new llist;
	new->prev = NULL;

	llist *prev = _data;
	llist *next = _ data;

	for(  ; str != NULL; prev = next->prev, str++, next = next->next;
	{
		 If ( new == NULL ) new->next = str;
		 New->prev = prev;
		 New->next = next;
	}

}

If( *this == str ) return *this;

}



*/
size_t StringList::size() const
{ 
	size_t n = 0;	

	if( _data == NULL )
		return n;
	n = 1;
	for( llist *head = _data; head->next != NULL  ; n++)
	{
		head = head->next;
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
	if( _data == NULL )
		std::cout << "undefined" << std::endl;
	llist *end = _data;
	
	while( end->next != NULL )
	{
		end = end->next;
	}
	return end->str;
	
}

void StringList::push_back (std::string c)
{
/*
	if( size() > max_size() )
		throw std::length_error("push_back");
*/
	llist *temp = new llist;
	temp->str = c;
	temp->next = NULL;
	
	if( _data == NULL)
	{
		_data = temp;
		return;
	}
	
	llist *end = _data;
	
	while( end->next != NULL )
	{
		end = end->next;
	}
	
	end->next = temp;
}

void StringList::pop_back()
{
	llist *temp, *prev;
	
	if( _data == NULL)
		return;
	
	else if( _data->next == NULL )
	{
		temp = _data;
		_data = NULL;
		delete temp;
	}
	else 
	{	
		temp = _data;
		while( temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		delete temp;
	}
}

void StringList::reverse()
{
	if( _data == NULL || size() <= 1 )
		return;
	llist *curr, *next, *prev;
	curr = _data;
	prev = NULL;
	while( curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	_data = prev;
}
