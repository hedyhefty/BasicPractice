#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	queueList q1;
	cout << q1.isEmpty() << endl;
	for (size_t i = 0; i < 5; ++i) {
		q1.enqueue(i);
	}

	while (!q1.isEmpty()) {
		cout << q1.dequeue() << " ";
	}

	cout << endl;
	cout << q1.isEmpty() << endl;

	for (size_t i = 0; i < 12; ++i) {
		q1.enqueue(i);
	}

	while (!q1.isEmpty()) {
		cout << q1.dequeue() << " ";
	}
}