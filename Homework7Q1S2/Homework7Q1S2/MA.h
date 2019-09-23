#pragma once
#include "BA.h"

class MA : public BA {
public:
	MA(int Id, int NOC, string N, string LN, int g[], bool r);

	bool milga();
	void print();

protected:
	bool research;
};