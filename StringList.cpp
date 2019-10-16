 #include "StringList.h"


/*
operator= 

basic_string& operator=( basic_string&& str );
{
Reminder: Op= Its wrong! Add prev to all functions 

llist *new = new llist;
new->prev = NULL;

llist *prev = _data;
llist *next = _ data;

If(   std::allocator_traits<Allocator>::propagate_on_container_move_assignment()   ) 
{
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
/*
StringList& StringList::operator=(StringList &)
{
    if (this != &str)
    {
        llist *curr, *newNode;

        curr = _data;
        newNode = NULL;

        while (curr)
        {
            newNode = curr->next;
            delete curr;
            curr = newNode;
        }

        llist *cptr = new llist;
        cptr = str._data;
        cptr->next = NULL;
	llist *temp = _data;
        temp = str._data->next;
        
	while (temp)
            {
                cptr->next = new llist;
                cptr->next = temp;
                cptr = cptr->next;
                cptr->next = NULL;
                temp = str._data->next;
            }
        }

    return *this;
}
*/
/*
StringList& StringList::Copy(const StringList & str)
{

	if( this == &str )
		_head = _tail = NULL; //_tail, _head ... _data;
	
	llist newList = new llist;
	while( str )
	{
		str._data->
	}
}
*//*
StringList& StringList::operator=(const StringList & str)
{

	if( this == &str )
		return *this;
	// llist *tmp = _data; //test
	//tmp.clear(); //test

	llist *next = _data;
	llist *prev = NULL;
	llist *newNode = new llist;

	while( str != NULL )
	{
		newNode->str = str;
		newNode->next = next;
		prev = newNode;
		newNode = newNode->next;
		newNode->next = NULL;
		newNode->prev = prev;
		str++;

	}

}

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
{*/
/*
	if( size() > max_size() )
		throw std::length_error("push_back");
*//*
	llist *temp = new llist;
	temp->str = c;
	temp->next = NULL;
	
	if( _data == NULL)
	{
		_data = temp;
		return;
	}
	
	llist *end = _data;
	llist *prev = NULL; // test 

	while( end->next != NULL )
	{
		prev->next = end; //test
		end = end->next;
	}
	
	end->next = temp;
	end->prev = prev;  //test
}

void StringList::pop_back()
{
	// delete link to prev 
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
		curr->prev = prev; // test
		curr = next;
	}
	_data = prev;
}*/
