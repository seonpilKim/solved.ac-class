#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, n;
	priority_queue<int, vector<int>, less<int>> maxheap;
	cin >> N;

	while (N--) {
		cin >> n;
		if (n == 0) {
			if (!maxheap.empty()) {
				cout << maxheap.top() << "\n";
				maxheap.pop();
			}
			else cout << "0\n";
		}
		else maxheap.push(n);
	}

	return 0;
}
