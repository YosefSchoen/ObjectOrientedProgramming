#pragma once
#include "List.h"

class RoundList : public List {
public:
	RoundList();

	void addToEnd(int val);
	int search(int n);

private:
};