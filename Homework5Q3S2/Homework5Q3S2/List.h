#pragma once
#include <iostream>
//#define nullptr NULL
using namespace std;

class List {
protected:

	//class List will have a class Link inside of it
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
	bool search(const int &value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	bool insert(int key);
	void remove(int key);
	void operator=(const List &);

	//friend functions for input output
	friend ostream &operator<<(ostream &out, List &);
	friend istream &operator >> (istream &in, List &);
	friend List merge(const List &x, const List &y);
	friend List makeSet(List &x);

protected:
	// data field 
	Link* head;
};
	