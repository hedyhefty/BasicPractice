#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

struct treeNode {
	int val = 0;
	treeNode* left = nullptr;
	treeNode* right = nullptr;
	treeNode(int x) :val(x) {}
};

enum class picType {
	num,
	space,
	left_slash,
	right_slash
};

struct picNode {
	int val = 0;
	picType ptype = picType::space;
};

// first: width, second: height
std::vector<int> calculateTreeParameters(int height) {
	std::vector<int> ans{ 0,0 };
	int n = height - 1;
	if (n == 0) {
		ans[0] = 1;
		ans[1] = 1;
		return ans;
	}

	ans[0] = 3 * pow(2, n) - 1;
	ans[1] = (ans[0] + 1) / 2;

	return ans;
}

int getHeight(treeNode* node) {
	if (!node) {
		return 0;
	}

	int left_h = 0;
	int right_h = 0;

	if (node->left) {
		left_h = getHeight(node->left);
	}

	if (node->right) {
		right_h = getHeight(node->right);
	}

	return 1 + std::max(left_h, right_h);
}

// current_h should start at 1.
void drawTree(std::vector<std::vector<picNode>>& pic, treeNode* node, int current_h, int height, int xbase, int ybase) {
	if (current_h == height) {
		return;
	}

	int dw = 0;

	int dh = height - current_h;

	std::vector<int> para = calculateTreeParameters(dh);

	int graph_dh;
	int graph_dw;

	if (dh > 1) {
		graph_dh = para[1];
		graph_dw = para[1];
	}
	else {
		graph_dh = 2;
		graph_dw = 2;
	}

	if (node->left) {
		int x_left = xbase - graph_dw;
		int y_left = ybase + graph_dh;
		pic[y_left][x_left].val = node->left->val;
		pic[y_left][x_left].ptype = picType::num;

		int j = y_left - 1;

		for (int i = x_left + 1; i < xbase; ++i) {
			pic[j][i].ptype = picType::left_slash;
			--j;
		}

		drawTree(pic, node->left, current_h + 1, height, x_left, y_left);
	}

	if (node->right) {
		int x_right = xbase + graph_dw;
		int y_right = ybase + graph_dh;
		pic[y_right][x_right].val = node->right->val;
		pic[y_right][x_right].ptype = picType::num;

		int j = ybase + 1;

		for (int i = xbase + 1; i < x_right; ++i) {
			pic[j][i].ptype = picType::right_slash;
			++j;
		}

		drawTree(pic, node->right, current_h + 1, height, x_right, y_right);
	}

}

void printTree(treeNode* root) {
	int height = getHeight(root);
	std::vector<int> para = calculateTreeParameters(height);
	int pic_height = para[1];
	int pic_width = para[0];

	// init graph
	std::vector<std::vector<picNode>> pic(pic_height, std::vector<picNode>(pic_width));

	int root_x = (pic_width - 1) / 2;
	int root_y = 0;

	pic[root_y][root_x].val = root->val;
	pic[root_y][root_x].ptype = picType::num;

	drawTree(pic, root, 1, height, root_x, root_y);

	std::cout << std::endl;
	for (auto row_it = pic.begin(); row_it != pic.end(); ++row_it) {
		std::cout << " ";
		for (auto col_it = row_it->begin(); col_it != row_it->end(); ++col_it) {
			if (col_it->ptype == picType::num) {
				std::cout << col_it->val;
			}
			else if (col_it->ptype == picType::space) {
				std::cout << " ";
			}
			else if (col_it->ptype == picType::left_slash) {
				std::cout << "/";
			}
			else if (col_it->ptype == picType::right_slash) {
				std::cout << "\\";
			}
		}
		std::cout << std::endl;
	}
}
