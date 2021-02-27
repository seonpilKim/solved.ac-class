#include <iostream>
#include <vector>

using namespace std;

vector<int> pre_order;

void post_order(int, int);

int main() {
	int node;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> node) pre_order.push_back(node);

	post_order(0, pre_order.size());

	return 0;
}

void post_order(int start, int end) {
	int left, right;
	int size_left = 0, size_right = 0;
	int root = pre_order[start];

	for (int idx = start + 1; idx < end; idx++) {
		if (pre_order[idx] < root) size_left++;
		else if (pre_order[idx] > root) size_right++;
	}

	left = start + 1 + size_left;
	right = left + size_right;
	if (size_left) post_order(start + 1, left);
	if (size_right) post_order(left, right);

	cout << root << '\n';
}