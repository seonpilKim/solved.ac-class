#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
	string T, P;
	int n = 0;
	vector<int> loc;
	queue<pair<int, int>> q;
	getline(cin, T);
	getline(cin, P);

	for (int i = 0; i < T.size(); i++) {
		if (T[i] == P[0]) q.push(make_pair(i, 0));
		int size = q.size();
		for (int j = 0; j < size; j++) {
			if (T[i] == P[q.front().second]) {
				q.front().second++;
				if (q.front().second == P.size()) {
					n++;
					loc.push_back(i - P.size() + 2);
					q.pop();
				}
				else {
					q.push(q.front());
					q.pop();
				}
			}
			else q.pop();		
		}
	}

	cout << n << "\n";
	for (int i : loc) {
		cout << i << "\n";
	}

	return 0;
}