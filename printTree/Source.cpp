#include <iostream>
#include <algorithm>
#include <vector>

#include "printTree.h"

using namespace std;

int main() {
	treeNode r(1);
	treeNode a(3);
	treeNode b(5);
	treeNode c(2);
	treeNode d(7);
	treeNode e(6);
	treeNode f(-2);
	r.left = &a;
	r.right = &b;
	a.left = &c;
	a.right = &d;
	d.left = &e;
	b.left = &f;

	printTree(&r);

	//int h = getHeight(&r);
	//vector<int> para = calculateTreeParameters(h);
	//cout << "width: " << para[0] << endl;
	//cout << "height:" << para[1] << endl;

	//vector<vector<picNode>> tgraph(para[1], vector<picNode>(para[0]));
	//tgraph[0][(para[0] - 1) / 2].val = r.val;
	//tgraph[0][(para[0] - 1) / 2].ptype = picType::num;
	//drawTree(tgraph, &r, 1, h, (para[0] - 1) / 2, 0);
	//for (auto it = tgraph.begin(); it != tgraph.end(); ++it) {
	//	for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
	//		if (it2->ptype == picType::space) {
	//			cout << " ";
	//		}
	//		else if (it2->ptype == picType::left_slash) {
	//			cout << "/";
	//		}
	//		else if (it2->ptype == picType::right_slash) {
	//			cout << "\\";
	//		}
	//		else {
	//			cout << it2->val;
	//		}
	//		//cout << " ";
	//	}
	//	cout << endl;
	//}
}

