#include <iostream>

#pragma once
struct doubleNode {
	int _val = 0;
	doubleNode* _prev = nullptr;
	doubleNode* _next = nullptr;
};

class doubleLinkList {
public:
	doubleNode* _head = nullptr;

	doubleNode* Search(int key) {
		doubleNode* ans = _head;
		while (ans->_val != key) {
			ans = ans->_next;
		}

		return ans;
	}

	void Insert(doubleNode* node) {
		node->_next = _head;
		if (_head) {
			_head->_prev = node;
		}

		_head = node;
	}

	void Delete(doubleNode* node) {
		if (node->_prev) {
			node->_prev->_next = node->_next;
		}
		else {
			_head = node->_next;
		}


		if (node->_next) {
			node->_next->_prev = node->_prev;
		}
	}

	void Print() {
		doubleNode* hold = _head;

		while (hold) {
			std::cout << hold->_val << " ";
			hold = hold->_next;
		}

		std::cout << std::endl;
	}

};