#include <iostream>
#include <string>

class StringList
{
	private:

	typedef struct llist {
		std::string value;
		struct llist *next;
		struct llist *prev;
	} llist;
	llist *_head;
	llist *_tail;
	size_t _count;

	public:
	// default constructor
	StringList()
	{
		_tail = 0;
		_head = 0;
		_count = 0; 
	}
	// copy constructor
	StringList(const StringList&);
	// destructor
	~StringList()
	{
		while(!empty())
			pop_front();
	}
	// copy operator
	StringList& operator=(const StringList& str)
	{
		if( this == &str )
			return *this;
		if( str._head == NULL)
		{
			_head = _tail = NULL; return *this;
		}
		
		llist *oldrusty = str._head;
		while( oldrusty->next != NULL )
		{
			llist *curr = oldrusty;
			push_back( curr->value);
			oldrusty->next = curr->next;
		}
		return *this;
	}
	std::string& front()
	{
		return _head->value;
	}
	std::string& back()
	{
		return _tail->value;
	}
	
	void push_front(std::string value)
	{
		if( _head == NULL )
		{
			llist *ptr = new llist;
			ptr->value = value;
			ptr->next = NULL;
			ptr->prev = NULL;
			_head = _tail = ptr;
			_count++;
			return;
			// _head->value = _tails->value = value;
			// _count++;
		}
		else
		{
			llist *newItem = new llist;
			newItem->prev = NULL;
			newItem->value = value;
			newItem->next = _head;

			_head->prev = newItem;
			_head = _head->prev;
			_count++;
/* GDB

(gdb) p *_head
$1 = {value = "E", next = 0x0, prev = 0x55555576b470}
(gdb) p *_tail
$2 = {value = "P", next = 0x0, prev = 0x55555576b4f0}
(gdb) 

correct prev and next on head.
*/

		}
	}

	void push_back (std::string value)
	{
		if( NULL == _tail )
		{
			llist *ptr = new llist;
			ptr->value = value;
			ptr->next = NULL;
			ptr->prev = NULL;
			_head = _tail = ptr;
			_count++;
			return;
			// _head->value = _tails->value = value;
			// _count++;
		}
		else 
		{
			llist *newItem = new llist;
			newItem->next = NULL;
			newItem->value = value;
			newItem->prev = _tail;
			_tail->next = newItem;
			_tail = _tail->next;
			_count++;
		}
	}
	void pop_front()
	{
		if( _tail )
		{
			llist *delete_me = _head;
			_head = _head->next;

			if( _tail )
				_head->prev = NULL;
			else 
				_head = NULL;

			delete delete_me;
			_count--;
		}
	}
	void pop_back()
	{
		if( _tail )
		{
			llist *delete_me_PLS = _tail;
			_tail = _tail->prev;
			
			if( _tail )
				_tail->next = NULL;
			else
				_head = NULL;

			delete delete_me_PLS;	
			_count--;
		}
	}
	void reverse ()
	{
		if( _head == _tail || size() == 1 )
			return;
		llist *tmp = NULL;
		llist *curr = _head;
		llist *ptr = curr->next;

		for( ; curr != NULL; ptr = ptr->next)
		{
			curr->prev = ptr;
			curr->next = tmp;
			ptr->next = curr;
			curr = curr ->prev;
		}
		_head = _tail;
		_tail = curr;	
	}
	bool empty() const
	{
		return (_head == NULL && _tail == NULL);
	}
	size_t size() const
	{
		size_t count = 0;
		if( _head == _tail)
			return count;
		for( llist *temp = _head; temp != NULL; temp = temp->next, count++ ){}
		return count;
	}
	void clear() noexcept
	{
		while( !empty() )
		{
			pop_back();
		}
	}

};
