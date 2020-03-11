#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& v, int begin, int end);

void mergeSort(vector<int>& v);

vector<int> merge(vector<int> v1, vector<int> v2);

void bubbleSort(vector<int>& v);

void insertionSort(vector<int>& v);

void selectionSort(vector<int>& v);

void quickSort(vector<int>& v);

int main() {
	vector<int> a = { 7,2,4,9,2,8,1,3,1 };
	//mergeSort(a, 0, a.size() - 1);
	//mergeSort(a);
	//bubbleSort(a);
	//insertionSort(a);
	//selectionSort(a);
	quickSort(a);

	for (auto i = a.begin(); i != a.end(); ++i) {
		cout << *i << " ";
	}

	cout << endl;
}

void quickSort(vector<int>& v) {
	if (v.size() <= 1) {
		return;
	}

	int pivot = v[v.size() - 1];
	vector<int> l;
	vector<int> r;

	for (auto i = v.begin(); i != v.end() - 1; ++i) {
		if (*i <= pivot) {
			l.push_back(*i);
		}
		else {
			r.push_back(*i);
		}
	}

	quickSort(l);
	quickSort(r);

	for (size_t i = 0; i < l.size(); ++i) {
		v[i] = l[i];
	}

	v[l.size()] = pivot;

	for (size_t i = 0; i < r.size(); ++i) {
		v[l.size() + 1 + i] = r[i];
	}
}

void selectionSort(vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		int min = i;
		for (size_t j = i + 1; j < v.size(); ++j) {
			if (v[j] < v[min]) {
				min = j;
			}
		}

		if (min != i) {
			int t = v[i];
			v[i] = v[min];
			v[min] = t;
		}
	}
}

void insertionSort(vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		size_t j = 0;
		for (; j < i; ++j) {
			if (v[i] < v[j]) {
				break;
			}
		}

		for (size_t k = i; k > j; --k) {
			int t = v[k];
			v[k] = v[k - 1];
			v[k - 1] = t;
		}
	}
}

void bubbleSort(vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		for (size_t j = 0; j < v.size() - i; ++j) {
			if (j + 1 == v.size()) {
				break;
			}

			if (v[j] > v[j + 1]) {
				int t = v[j];
				v[j] = v[j + 1];
				v[j + 1] = t;
			}
		}
	}
}

void mergeSort(vector<int>& v) {
	if (v.size() <= 1) {
		return;
	}

	int mid = (v.size() - 1) / 2;

	vector<int> v1(v.begin(), v.begin() + mid + 1);
	vector<int> v2(v.begin() + mid + 1, v.end());

	mergeSort(v1);
	mergeSort(v2);

	v = merge(v1, v2);
}

vector<int> merge(vector<int> v1, vector<int> v2) {
	vector<int> ans;
	auto iter1 = v1.begin();
	auto iter2 = v2.begin();

	while (iter1 != v1.end() || iter2 != v2.end()) {
		if (iter1 == v1.end()) {
			ans.push_back(*iter2);
			iter2++;
		}
		else if (iter2 == v2.end()) {
			ans.push_back(*iter1);
			iter1++;
		}
		else {
			if (*iter1 < *iter2) {
				ans.push_back(*iter1);
				iter1++;
			}
			else {
				ans.push_back(*iter2);
				iter2++;
			}
		}
	}

	return ans;
}

void mergeSort(vector<int>& v, int begin, int end) {
	if (begin == end) {
		return;
	}

	int mid = (begin + end) / 2;
	mergeSort(v, begin, mid);
	mergeSort(v, mid + 1, end);

	vector<int> l(v.begin() + begin, v.begin() + mid + 1);
	vector<int> r(v.begin() + mid + 1, v.begin() + end + 1);

	auto iterl = l.begin();
	auto iterr = r.begin();

	int i = begin;

	while (iterl != l.end() || iterr != r.end()) {
		if (iterl == l.end()) {
			v[i] = *iterr;
			iterr++;
		}
		else if (iterr == r.end()) {
			v[i] = *iterl;
			iterl++;
		}
		else {
			if (*iterl < *iterr) {
				v[i] = *iterl;
				iterl++;
			}
			else {
				v[i] = *iterr;
				iterr++;
			}
		}
		i++;
	}
}