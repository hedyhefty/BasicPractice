#pragma once

struct stackNode {
	int _val = 0;
	stackNode* _next = nullptr;
};

class myStackl {
public:
	bool isEmpty() {
		if (_top) {
			return false;
		}

		return true;
	}

	int top() {
		if (isEmpty()) {
			return -1;
		}

		return _top->_val;
	}

	void push(int val) {
		stackNode* n = new stackNode;
		n->_val = val;
		n->_next = _top;
		_top = n;
	}

	void pop() {
		if (isEmpty()) {
			return;
		}
		stackNode* hold = _top;
		_top = _top->_next;
		delete hold;
	}

private:
	stackNode* _top = nullptr;
};