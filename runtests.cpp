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
	// TODO:
	// Write *at least* 15 more tests to fully test
	// your class.

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
	Assert(a.back() == "B", "pop_back method");
	a.pop_front(); // delete C _ A,B
	Assert(a.front() == "A", "front method");
	a.pop_back();  // delete B _ A
	Assert(a.back() == "A", "back method");
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	Assert(a.size() == 1, "size method");
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
	
	return 0;
}


