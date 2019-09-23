#include "RoundList.h"

RoundList::RoundList() {

}


void RoundList::addToEnd(int val) {
	Link *p = head;
	int listSize = 0;

	if (isEmpty()) {
		p = new Link(val, nullptr);
		p->next = head;
	}

	else {
		for (p = head; p != nullptr; p = p->next) {

		}

		p->next = new Link(val, nullptr);
		p = p->next;
		p->next = head;
	}
}

int RoundList::search(int n) {
	// loop to find size of the list
	Link *p = head;
	int listSize = 0;
	for (p = head; p != nullptr; p = p->next) {
		listSize++;
	}
	
	p = head;
	for (int i = 0; i < n % listSize; i++) {
		p = p->next;
	}

	return p->value;
}