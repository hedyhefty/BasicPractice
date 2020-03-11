#include <iostream>
#include <vector>
#include "Header.h"

using namespace std;

int main() {
	doubleLinkList dbll;
	vector<doubleNode> dbv(10);

	for (size_t i = 0; i < 10; ++i) {
		dbv[i]._val = i;
		dbll.Insert(&dbv[i]);
	}

	dbll.Print();
	dbll.Delete(dbll.Search(3));
	dbll.Print();
	dbll.Delete(dbll.Search(9));
	dbll.Print();
	dbll.Delete(dbll.Search(0));
	dbll.Print();
	doubleNode d;
	d._val = 10;
	dbll.Insert(&d);
	dbll.Print();
}