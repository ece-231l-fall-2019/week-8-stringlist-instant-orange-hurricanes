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
	StringList& operator=(const StringList& a)
	{
		for (const llist* b = a._head; b != 0; b = b->next)
		{
			push_back(b->value);
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
		if( _head->next == NULL )
			return;
		llist *temp;
		llist *curr = _head;
		while( curr != NULL )
		{
			temp = curr->prev;
			curr->prev = curr->next;
			curr->next = temp;
			curr = curr->prev;
		}
		temp = temp->prev;
		if( temp != NULL)
			temp = temp->prev;
		_tail = _head;
		_head = temp;
/*
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
		_tail = curr;	*/
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
	
	void unique()
	{
		for (llist *i = _tail; i != 0; i = i -> next)
		{
			while( i -> next != 0 && i -> value == i -> next -> value)
			{
				llist *save = i -> next;
				i -> next = save -> next;

				if (save -> next != 0)
				{
					save -> next ->prev = i;
					delete save;
				}
				else
				{
					_tail = i;
					delete save;
				}
			}
		}
	}
	

};
