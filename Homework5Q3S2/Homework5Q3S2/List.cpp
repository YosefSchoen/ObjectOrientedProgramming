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

bool  List::search(const int &val) const {
	// loop to test each element 
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found 
	return false;
}

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

bool List::insert(int key) {
	//if value is already in List return false
	if (search(key) == true) {
		return false;
	}

	else {
		//placing the new value before the first value if the first value is greater
		if (head->value > key) {
			head = new Link(key, head);
			return true;
		}

		for (Link* p = head; ; p = p->next) {
			//if at the end of List the last link will point to this new one
			if (p->next == nullptr) {
				p->next = new Link(key, nullptr);
				return true;
			}

			//if the value is between two values in List insert it between them
			else if (key > p->value && key < ((p->next)->value)) {
				p->next = new Link(key, p->next);
				return true;
			}
		}
	}
}


void List::remove(int key) {
	//if the value does not exist throw not found
	if (search(key) == false || isEmpty() == true) {
		throw "value not found";
	}

	//if the first value in List is the key make the head point to the next value
	if (head->value == key) {
		head = head->next;
	}

	else {
		Link *p = head;

		while (true) {

			//if the next value is equal to key skip that link to the next next link
			if (p->next != nullptr && (p->next)->value == key)
			{
				p->next = ((p->next)->next);
				break;
			}
			p = p->next;
		}
	}
}

//make p point to the other list
void List::operator=(const List &other) {
	Link *p = other.head;

}

//outputing the values in List until it points to NULL
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

//inputing values into List until a value is smaller than the others
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

List merge(const List& list1, const List& list2) {
	List *tmp = new List;
	List::Link* p1 = list1.head;
	List::Link* p2 = list2.head;

	if (p1 == nullptr && p2 == nullptr) {
		return *tmp;
	}

	while (p1 != nullptr && p2 != nullptr) {
		if (p1 == nullptr || p1->value >= p2->value) {
			tmp->insert(p2->value);
			p2 = p2->next;
		}
		else {
			tmp->insert(p1->value);
			p1 = p1->next;
		}
	}
	while (p2 != nullptr) {
		tmp->insert(p2->value);
		p2 = p2->next;
	}
	while (p1 != nullptr) {
		tmp->insert(p1->value);
		p1 = p1->next;
	}
	return *tmp;
}

List makeSet(List& other) {
	List::Link* p1 = other.head;

	while (p1->next != nullptr) {
		if (p1->value == ((p1->next)->value)) {
			other.remove(p1->value);
		}
		p1 = p1->next;
	}

	return other;
}