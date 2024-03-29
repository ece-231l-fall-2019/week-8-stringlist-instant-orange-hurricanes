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

int main()
{
/*	StringList e;

	e.push_back("A");
	e.push_back("B");
	e.push_front("C");
	e.push_front("D");
	e.push_back("E");
	e.print("StringList e");	
*/	
	StringList a;

	a.push_back("A");
	a.push_back("B");
	a.push_front("C");
	a.push_front("D");
	a.push_back("E");
	a.print("StringList a");

	// D,C,A,B,E	
	Assert(a.size() == 5, "a.size() = 5");
	Assert(a.front() == "D", "a.front = 'D'");
	a.pop_front(); // delete D _ C,A,B,E
	Assert(a.front() == "C", "a.pop_front(): a.front = 'C'");
	Assert(a.back() == "E", "a.back() = 'E'");
	a.pop_back();  // delete E _ C,A,B
	Assert(a.back() == "B", "a.pop_back(): a.back() = 'B'");
	a.pop_front(); // delete C _ A,B
	Assert(a.front() == "A", "a.front() = 'A'");
	a.pop_back();  // delete B _ A
	Assert(a.back() == "A", "a.pop_back(): a.back = 'A'");
	Assert(a.size() == 1, "a.size() = 1");
	Assert(a.front()== "A","a.front() = 'A'");

	a.push_back("B");
	a.push_back("R");
	a.push_front("Q");
	a.push_back("T");
	a.push_front("Z");
	a.print("StringList a: round 2");
	
	// Z,Q,A,B,R,T
	Assert(a.front() == "Z", "a.front() = 'Z'");
	a.pop_back(); // Z,Q,A,B,R
	Assert(a.front() == "Z", "a.pop_back(): a.front() = 'Z'");
	a.pop_front(); // Q,A,B,R
	Assert(a.back() == "R", "a.pop_front: a.back() = 'R'");
	a.pop_back(); // Q,A,B
	Assert(a.back() == "B", "a.pop_back(): a.back() = 'B'");
	//===============================^davids OG//
	
	//operator =
	StringList t;

	t.push_back("A");
	t.push_back("B");
	t.push_front("C");
	t.push_front("D");
	t.push_back("E");
	t.print("StringList t");
	
	StringList T;		
	T = t;
	t.print("StringList T");

	Assert(T.front() == "D", "operator=: T.front() = D");	
	Assert(T.back() == "E", "operator=: T.back() = E");

	StringList j;
	j = T;	
	j.print("StringList j");

	Assert(j.front() == "D", "operator=: j.front() = D");	
	Assert(j.back() == "E", "operator=: j.back() = E");
	
	//empty
	StringList f;
	Assert(f.empty() == true, "f.empty(): f is empty");
	
	StringList i;
	
	i.push_back("L");
	i.push_back("O");
	i.push_back("L");
	i.print("StringList i");

	Assert(i.empty() == false, "i.empty(): f is not empty");

	//clear	
	StringList g;
	
	g.push_back("F");
	g.print("StringList g");

	StringList h;
	
	h.push_back("H");
	h.print("StringList h");
	
	StringList k;
	
	k.push_back("G");
	k.print("StringList G");
	
	g.clear();
	h.clear();
	k.clear();
	
	Assert(g.size() == 0, "g.clear(): StringLists of contents!");
	Assert(h.size() == 0, "h.clear(): StringLists of contents!");
	Assert(k.size() == 0, "k.clear(): StringLists of contents!");
	
	//reverse
	StringList b; 
	
	b.push_back("E");
	b.push_back("N");
	b.push_back("O");
	b.push_back("H");
	b.push_back("P");
	b.print("StringList b");
	b.reverse();
	
	/*StringList B;
	B.push_back("P");
	B.push_back("H");
	B.push_back("O");
	B.push_back("N");
	B.push_back("E");
	B.print("StringList 'B'");
	*/
	Assert(b.front() == "P", "b.reverse(): ENOHP -> PHONE");
	Assert(b.back() == "E", "test 1: checking b.back() = E");
	Assert(b.size() == 5, "test 2: checking b.size() = 5");
	b.print("StringList b: post-reverse");
	
	//unique
	StringList c;
	
	c.push_back("J");
	c.push_back("A");
	c.push_back("Z");
	c.push_back("Z");
	c.push_back("Z");
	c.print("StringList c");

	c.unique();
	
	/*StringList C;	
	C.push_back("J");
	C.push_back("A");
	C.push_back("Z");
	C.print("StringList 'C'");
	*/

	Assert(c.front() == "J", "unique: JAZZZ -> JAZ");
	Assert(c.back() == "Z", "test 1: checking c.back() = Z");
	Assert(c.size() == 3, "test 2: checking c.size() = 3");
	c.print("StringList c: post_unique");
	
	StringList d;
	
	d.push_back("B");
	d.push_back("A");
	d.push_back("A");
	d.push_back("A");
	d.push_back("N");
	d.push_back("N");
	d.print("StringList d");
	/*	
	StringList D;
	D.push_back("B");
	D.push_back("A");
	D.push_back("N");
	D.print("StringList 'D'");
	*/
	d.unique();

	Assert(d.front() == "B", "unique: BAAANN -> BAN");
	Assert(d.back() == "N", "test 1: checking d.back() = N");
	Assert(d.size() == 3, "test 2: checking d.size() = 3");
	d.print("StringList d: post_unique");
	
	return 0;
}
