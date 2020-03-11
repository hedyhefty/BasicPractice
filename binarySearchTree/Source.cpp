#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	binarySearchTree t;
	t.Insert(6);
	t.Insert(3);
	t.Insert(7);
	t.Insert(1);
	t.Insert(5);
	t.Insert(4);
	t.Insert(10);

	auto res1 = t.Search(3);
	auto res2 = t.Search(5);
	auto res3 = t.Search(6);

	t.Delete(res3);

	return 0;
}