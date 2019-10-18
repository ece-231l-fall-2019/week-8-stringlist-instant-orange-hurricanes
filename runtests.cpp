#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#if 1
#include "StringList.h"
#else
#include <list>
#include <string>
typedef std::list<std::string> StringList;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

<<<<<<< HEAD
void StringList::print() const
=======

int main()
>>>>>>> b384d86c4992406653fd6e9e25ea6ccd74625f8c
{
	while (_head != NULL)
	{
		cout << _head->data << endl;
		_head = _head->next;
	}
}

<<<<<<< HEAD
int main()
{
	
=======

	// a.print() 

>>>>>>> b384d86c4992406653fd6e9e25ea6ccd74625f8c
	StringList e;

	e.push_back("A");
	e.push_back("B");
	e.push_front("C");
	e.push_front("D");
	e.push_back("E");
	a.print();

/*
	StringList a;

	a.push_back("A");
	a.push_back("B");
	a.push_front("C");
	a.push_front("D");
	a.push_back("E");

	// D,C,A,B,E	
	Assert(a.size() == 5, "size method");
	Assert(a.front() == "D", "front method");
	a.pop_front(); // delete D _ C,A,B,E
	Assert(a.front() == "C", "pop_front method");
	Assert(a.back() == "E", "back method");
	a.pop_back();  // delete E _ C,A,B
	Assert(a.back() == "B", "pop_back method L_45");
	a.pop_front(); // delete C _ A,B
	Assert(a.front() == "A", "front method");
	a.pop_back();  // delete B _ A
	Assert(a.back() == "A", "back method L_49");
	Assert(a.size() == 1, "size method L_52");
	Assert(a.front()== "A","front method");

	a.push_back("B");
	a.push_back("R");
	a.push_front("Q");
	a.push_back("T");
	a.push_front("Z");
	// Z,Q,A,B,R,T
	Assert(a.front() == "Z", "front method");
	a.pop_back(); // Z,Q,A,B,R
	Assert(a.front() == "Z", "front method");
	a.pop_front(); // Q,A,B,R
	Assert(a.back() == "R", "pop_front");
	a.pop_back(); // Q,A,B
	Assert(a.back() == "B", "pop_back");
	//===============================^davids OG//
	
	
	//operator =
	StringList t;

	t.push_back("A");
	t.push_back("B");
	t.push_front("C");
	t.push_front("D");
	t.push_back("E");
	
	StringList T;		
	t = T;

	Assert(t == T, "operator =: ABCDE = ABCDE");
	
	StringList j;
	j = T;	

	Assert(T == j, "operator=: ABCDE = ABCDE");
	
	//empty
	StringList f;
	Assert(f.empty() == true, "f.empty: f is empty");
	
	StringList i;
	i.push_back("L");
	i.push_back("O");
	i.push_back("L");
	Assert(i.empty() == false, "i.empty: f is not empty");

	//clear	
	StringList g;
	g.push_back("F");

	StringList h;
	h.push_back("H");
	
	StringList k;
	k.push_back("G");
	
	g.clear();
	h.clear();
	k.clear();
	
	Assert(g == h, "cleared g StringLists of contents!");
	Assert(h == k, "cleared h StringLists of contents!");
	Assert(k == g, "cleared k StringLists of contents!");
	
	//reverse
	StringList b; 
	b.push_back("E");
	b.push_back("N");
	b.push_back("O");
	b.push_back("H");
	b.push_back("P");
	
	b.reverse();
	StringList B;
	B.push_back("P");
	B.push_back("H");
	B.push_back("O");
	B.push_back("N");
	B.push_back("E");
	
	Assert(b == B, "reverse: ENOHP -> PHONE");
	
	//unique
	StringList c;
	c.push_back("J");
	c.push_back("A");
	c.push_back("Z");
	c.push_back("Z");
	c.push_back("Y");

	c.unique();
	StringList C;	
	C.push_back("J");
	C.push_back("A");
	C.push_back("Z");
	C.push_back("Y");

	Assert(c == C, "unique: JAZZY -> JAZY");
	
	StringList d;
	d.push_back("B");
	d.push_back("A");
	d.push_back("A");
	d.push_back("A");
	d.push_back("N");
	d.push_back("N");
		
	StringList D;
	D.push_back("B");
	D.push_back("A");
	D.push_back("N");
	
	d.unique();
<<<<<<< HEAD
	Assert(d == D, "unique: BAAANN -> BAN");
*/	
=======
//	Assert(d == D, "unique: BAAANN -> BAN");
	
>>>>>>> b384d86c4992406653fd6e9e25ea6ccd74625f8c
	return 0;
}
