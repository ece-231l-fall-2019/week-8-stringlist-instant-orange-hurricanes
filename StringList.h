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
	
	//print function
	void print(std::string message)
	{
		std::cout<<"-----------------"<<std::endl;
		std::cout<<message<<std::endl;
		for( llist *ptr = _head ; ptr != NULL; ptr = ptr->next)
			std::cout << ptr->value << " ";
		std::cout<< std::endl;
		std::cout<<"-----------------"<<std::endl;
	}
/*
	bool operator==(StringList& a, StringList& b)
	{
		if(a.size() == b.size())
		{
			while( a._head->value == b._head->value )
			{
				a._head == b._head->next;
				b._head == b._head->next; 
			}

			llist* bptr = b.front();
			for (; aptr && bptr != 0; aptr = aptr->next, bptr = bptr-> next)
			{
				if (aptr == bptr)
				{	
					return true;
				}
				return false;
			}
		}
		return false;
	}
*/
	void push_front(std::string value)
	{
		llist *ptr = new llist;
		ptr->value = value;

		ptr->prev = NULL;
		ptr->next = _head;
		if( _head != NULL)
			_head->prev = ptr;
		if( _head == NULL )
			_head = ptr;
		_head = ptr;
		_count++;
		
	}

	void push_back (std::string value)
	{
		llist *ptr = new llist;
		ptr->value = value;
		ptr->next = NULL;
		ptr->prev = _tail;
		if( _tail != NULL)
			_tail->next = ptr;
		if( _head == NULL )
			_head = ptr;
		_tail = ptr;
		_count++;
	}
	void pop_front()
	{
		llist *delete_me = _head;
		_head = _head->next;
		if( _head )
			_head->prev = _head->prev->prev;
		else 
			_tail = NULL;

		delete delete_me;

	}
	void pop_back()
	{
		llist *delete_me = _tail;
		_tail = _tail->prev;
		if( _tail )
			_tail->next = _tail->next->next;
		else 
			_head = NULL;

		delete delete_me;
	}
	void reverse ()
	{
		if( size() <= 1 )
			return;
		llist *curr = _head;
		llist *tmp;
		while( curr != NULL )
		{
			tmp = curr->prev;
			curr->prev = curr->next;
			curr->next = tmp;
			curr = curr->prev;
		}	
		if(tmp)
			tmp = tmp->prev;
		_head = tmp;
	}

	bool empty() const
	{
		return size() == 0;
	}

	size_t size() const
	{
		size_t count = 0;
		if( _head == NULL ) 
			return count;
		if( _head == _tail)
		{
			count++;
			return count;
		}

		for( llist *temp = _head; temp != NULL; temp = temp->next, count++ ){}
		
		return count;
	}

	void clear()// noexcept
	{
		while( !empty())
		{
			pop_back();
		}
	}
	
	void unique()
	{
		for (llist *i = _head; i != 0; i = i -> next)
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
					_head = i;
					delete save;
				}
			}
		}
	}
	

};
/*

	void unique()
	{	
		for (llist *ptr = _head; ptr != 0; ptr = ptr -> next)
		{
			if( ptr->next != NULL && ptr->value == ptr->next->value )
			{
				llist *savedPtr = ptr->next;
				ptr->next = savedPtr->next;
				if( savedPtr->next != NULL)
				{
					savedPtr->next->prev = ptr;
				}
				else 
					_tail = ptr;
				delete savedPtr;
				_count--;
			}
		}
	}	
*/
