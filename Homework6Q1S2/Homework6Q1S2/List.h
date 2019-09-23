#pragma once
#include <iostream>
//#define nullptr NULL
using namespace std;

class List {
protected:
	class Link {
	public:
		//constructor 
		Link(int linkValue, Link *nextPtr);
		Link(const Link &);
		// data areas 
		int value;
		Link *next;
	};

public:
	// constructors 
	List();
	List(const List&);
	~List();

	// operations 
	void add(int value);
	int firstElement() const;
	//bool search(const int &value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();

	/*
	bool insert(int key);
	void remove(int key);
	void operator=(const List &);

	friend ostream &operator<<(ostream &out, List &);
	friend istream &operator >> (istream &in, List &);
	friend List merge(List x, List y);
	friend List makeSet(List x);
	*/
protected:
	// data field 
	Link* head;
};



/*

List& List::operator=(const List& other)
{
// check if this and other are the same
if (this == &other) return *this;

if (other.isEmpty()) {
clear();
return *this;
}

Link* o_link = other.head;
Link* t_link = head;

// determine first value of new list
if (!isEmpty()) {
head->value = other.head->value;
}
else {
head = new Link(other.head->value, nullptr);
}

// copy values from other to this
while (o_link->next != nullptr && t_link->next != nullptr) {
o_link = o_link->next;
t_link = t_link->next;
t_link->value = o_link->value;
}

// if this is too short create more links to hold the remainder of other's values
while (o_link->next != nullptr) {
o_link = o_link->next;
t_link->next = new Link(o_link->value, nullptr);
t_link = t_link->next;
}

// if this is too long, delete the extraneous links
if (t_link->next != nullptr) t_link = t_link->next;

Link* next;
for (; t_link != nullptr; t_link = next) {
next = t_link->next;
t_link->next = nullptr;
delete t_link;
}

return *this;
}

*/