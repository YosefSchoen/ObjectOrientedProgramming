#include "List.h"

List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {}

List::Link::Link(const Link& source) : value(source.value), next(source.next) {}

List::List() : head(nullptr) {
	// no further initialization
}

List::List(const List &l) {
	Link *src, *trg;
	if (l.head == nullptr)
		head = nullptr;
	else {
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr) {
			trg->next = new Link
			((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}

List::~List() {
	clear();
}

void List::clear() {
	// empty all elements from the List 
	Link* next;

	// delete the element pointed to by p 
	for (Link * p = head; p != nullptr; p = next) {
		next = p->next;
		p->next = nullptr;
		delete p;
	} // mark that the List contains no elements 
	head = nullptr;
}

bool List::isEmpty() const {
	// test to see if the List is empty 
	// List is empty if the pointer to the head 
	// Link is null 

	return head == nullptr;
}

void List::add(int val) {
	//Add a new value to the front of a Linked List 
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

int List::firstElement() const {
	// return first value in List 
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}


/*bool List::search(const int &val) const {
	// loop to test each element 
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found 
	return false;
}
*/

void List::removeFirst() {
	// make sure there is a first element 
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node 
	Link* p = head;
	// reassign the first node 
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element 
	delete p;
}

/*
bool List::insert(int key) {

	if (search(key) == true) {
		return false;
	}

	else {
		if (head->value > key) {
			head = new Link(key, head);
			return true;
		}

		for (Link* p = head; ; p = p->next) {
			if (p->next == nullptr) {
				p->next = new Link(key, nullptr);
				return true;
			}

			else if (key > p->value && key < ((p->next)->value)) {
				p->next = new Link(key, p->next);
				return true;
			}
		}
	}
}


void List::remove(int key) {
	if (search(key) == false || isEmpty() == true) {
		throw "value not found";
	}

	if (head->value == key) {
		head = head->next;
	}

	else {
		Link *p = head;

		while (true) {
			if (p->next != nullptr && (p->next)->value == key)
			{
				p->next = ((p->next)->next);
				break;
			}
			p = p->next;
		}
	}
}

void List::operator=(const List &other) {
	Link *p = other.head;

}

ostream &operator<<(ostream &out, List &other) {

	List temp(other);
	while (true) {
		out << temp.head->value << ' ';

		if (temp.head->next == nullptr) {
			break;
		}

		temp.head = temp.head->next;
	}
	return out;
}

istream &operator >> (istream &in, List &other) {

	int val;
	in >> val;

	if (other.head == nullptr) {
		other.add(val);
	}

	while (true) {
		in >> val;

		if (other.insert(val) != true) {
			return in;
		}
	}
	return in;
}
*/