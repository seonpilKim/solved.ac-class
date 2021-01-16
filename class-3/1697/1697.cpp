#include <iostream>
#include <queue>
using namespace std;

int n, k, visited[100001];
queue<int> q;

int BFS();

int main() {
	cin >> n >> k;
	cout << BFS();

	return 0;
}

int BFS() {
	q.push(n);
	visited[n] = 1;

	while (!q.empty()) {
		int p = q.front(); q.pop();
		if (p == k) return visited[p] - 1;

		if (p - 1 >= 0 && visited[p - 1] == 0) {
			visited[p - 1] = visited[p] + 1;
			q.push(p - 1);
		}

		if (p + 1 < 100000 && visited[p + 1] == 0) {
			visited[p + 1] = visited[p] + 1;
			q.push(p + 1);
		}

		if (2 * p < 100000 && visited[2 * p] == 0) {
			visited[2 * p] = visited[p] + 1;
			q.push(2 * p);
		}
	}
}