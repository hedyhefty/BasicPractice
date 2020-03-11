#pragma once

class queueArray {
public:
	void enqueue(int val) {
		if (_c_size == _size) {
			return;
		}

		if (_c_size == 0) {
			_q[_begin] = val;
		}
		else {
			_q[_end] = val;
			_end++;
			if (_end == _size) {
				_end = 0;
			}
		}

		_c_size++;
	}

	int dequeue() {
		if (_c_size == 0) {
			return -1;
		}

		int hold = _q[_begin];

		if (_c_size > 1) {
			_begin++;
			if (_begin == _size) {
				_begin = 0;
			}
		}

		_c_size--;
		return hold;
	}

	bool isEmpty() {
		if (_c_size == 0) {
			return true;
		}

		return false;
	}

private:
	int _q[10] = { 0 };
	int _begin = 0;
	int _end = 1;
	int _size = 10;
	int _c_size = 0;
};

struct queueNode {
	int _val = 0;
	queueNode* _next = nullptr;
};

class queueList {
public:
	bool isEmpty() {
		if (!_head) {
			return true;
		}

		return false;
	}

	void enqueue(int val) {
		queueNode* n = new queueNode;
		n->_val = val;

		if (isEmpty()) {
			_head = n;
			_tail = n;
		}
		else {
			_tail->_next = n;
			_tail = n;
		}
	}

	int dequeue() {
		if (isEmpty()) {
			return -1;
		}

		queueNode* hold = _head;
		int ans = hold->_val;

		if (!_head->_next) {
			_tail = nullptr;
		}

		_head = _head->_next;
		delete hold;
		return ans;
	}

private:
	queueNode* _head = nullptr;
	queueNode* _tail = nullptr;
};