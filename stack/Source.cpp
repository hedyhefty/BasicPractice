#include <iostream>
#include "Header.h"
using namespace std;

struct myStack {
	int s[10] = { 0 };
	int top = 0;
};

bool isEmpty(myStack s);
int pop(myStack &s);
void push(myStack &s, int val);

int main() {
	/*myStack s;
	cout << isEmpty(s) << endl;
	cout << pop(s) << endl;
	push(s, 1);
	push(s, 1);
	push(s, 3);
	push(s, 2);
	while (!isEmpty(s)) {
		cout << pop(s) << " ";
	}
	cout << endl;*/

	myStackl ms;
	cout << ms.isEmpty() << endl;
	cout << ms.top() << endl;
	ms.pop();
	ms.push(1);
	ms.push(1);
	ms.push(3);
	ms.push(2);

	while (!ms.isEmpty()) {
		cout << ms.top() << " ";
		ms.pop();
	}
	ms.push(19);
	cout << ms.top() << endl;
	ms.pop();
	cout << ms.isEmpty() << endl;
}

bool isEmpty(myStack s) {
	if (s.top == 0) {
		return true;
	}

	return false;
}

int pop(myStack& s) {
	if (isEmpty(s)) {
		return -1;
	}

	int hold = s.s[s.top];
	s.top--;
	return hold;
}

void push(myStack& s, int val) {
	s.top++;
	s.s[s.top] = val;
}
