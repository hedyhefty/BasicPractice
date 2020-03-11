#include<iostream>

using namespace std;

void maxHeapify(int a[], int n, int i);

void buildMaxheap(int a[], int n);

int extractMax(int a[], int &n);

void heapSort(int a[], int n);

int main() {
	int a[] = {1,7,4,5,8,2,3};
	int n = sizeof(a) / sizeof(int);
	buildMaxheap(a, n);
	for (size_t i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;

	cout << extractMax(a, n) << endl;

	for (size_t i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	heapSort(a, n);
	for (size_t i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
}

void maxHeapify(int a[], int n, int i) {
	int op = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[op]) {
		op = l;
	}

	if (r < n && a[r] > a[op]) {
		op = r;
	}

	if (op != i) {
		int t = a[op];
		a[op] = a[i];
		a[i] = t;

		maxHeapify(a, n, op);
	}
}

void buildMaxheap(int a[], int n) {
	for (size_t i = n / 2 - 1;; i--) {
		maxHeapify(a, n, i);

		// deal with size_t's problem.
		if (i == 0) {
			break;
		}
	}
}

int extractMax(int a[], int &n) {
	if (n == 0) {
		return -1;
	}

	int hold = a[0];

	a[0] = a[n - 1];
	n--;
	maxHeapify(a, n, 0);

	return hold;
}

void heapSort(int a[], int n) {
	for (size_t i = 0; i < n; ++i) {
		int hold = a[0];
		a[0] = a[n - i - 1];
		a[n - i - 1] = hold;
		maxHeapify(a, n - i - 1, 0);
	}
}