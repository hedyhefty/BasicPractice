#pragma once
struct treeNode {
	int _val = 0;
	treeNode* _parent = nullptr;
	treeNode* _left = nullptr;
	treeNode* _right = nullptr;
};

class binarySearchTree {
private:
	treeNode* Search_private(treeNode* x, int k) {
		if (x == nullptr || x->_val == k) {
			return x;
		}
		else if (x->_val < k) {
			return Search_private(x->_right, k);
		}
		else {
			return Search_private(x->_left, k);
		}
	}

	treeNode* FindSuccessor(treeNode* node) {
		node = node->_left;

		while (node->_right) {
			node = node->_right;
		}

		return node;
	}

	treeNode* _root = nullptr;

public:
	treeNode* Search(int k) {
		return Search_private(_root, k);
	}

	void Insert(int val) {
		if (!_root) {
			_root = new treeNode;
			_root->_val = val;
			return;
		}

		treeNode* hold = _root;
		treeNode* hold_parent = nullptr;

		while (hold) {
			hold_parent = hold;
			if (hold->_val < val) {
				hold = hold->_right;
			}
			else {
				hold = hold->_left;
			}
		}

		treeNode* nnode = new treeNode;
		nnode->_val = val;

		if (val < hold_parent->_val) {
			hold_parent->_left = nnode;
			nnode->_parent = hold_parent;
		}
		else {
			hold_parent->_right = nnode;
			nnode->_parent = hold_parent;
		}

	}

	void Delete(treeNode* node) {
		if (!node->_left && !node->_right) {
			if (node->_parent) {
				if (node == node->_parent->_left) {
					node->_parent->_left = nullptr;
				}
				else {
					node->_parent->_right = nullptr;
				}
			}
		}
		else if (node->_left && !node->_right) {
			if (node->_parent) {
				if (node == node->_parent->_left) {
					node->_parent->_left = node->_left;
				}
				else {
					node->_parent->_right = node->_left;
				}
				node->_left->_parent = node->_parent;
			}
			else {
				node->_left->_parent = nullptr;
				_root = node->_left;
			}
		}
		else if (node->_right && !node->_left) {
			if (node->_parent) {
				if (node == node->_parent->_left) {
					node->_parent->_left = node->_right;
				}
				else {
					node->_parent->_right = node->_right;
				}
				node->_right->_parent = node->_parent;
			}
			else {
				node->_right->_parent = nullptr;
				_root = node->_right;
			}
		}
		else {
			treeNode* successor = FindSuccessor(node);
			if (successor->_left) {
				if (successor == successor->_parent->_left) {
					successor->_parent->_left = successor->_left;
				}
				else {
					successor->_parent->_right = successor->_left;
				}
				successor->_left->_parent = successor->_parent;
			}
			else {
				if (successor == successor->_parent->_left) {
					successor->_parent->_left = nullptr;
				}
				else {
					successor->_parent->_right = nullptr;
				}
			}

			node->_val = successor->_val;

			delete successor;
			return;
		}

		delete node;
	}
};