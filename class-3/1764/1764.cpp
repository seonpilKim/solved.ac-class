#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, M, idx;
	vector<string> n, m, nm;
	string input;

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		n.push_back(input);
	}
	sort(n.begin(), n.end());
	n.erase(unique(n.begin(), n.end()), n.end());

	for (int i = 0; i < M; i++) {
		cin >> input;
		m.push_back(input);
	}
	sort(m.begin(), m.end());
	m.erase(unique(m.begin(), m.end()), m.end());

	for (int i = 0; i < N; i++) {
		idx = lower_bound(m.begin(), m.end(), n[i]) - m.begin();
		if (idx < M && m[idx] == n[i]) nm.push_back(n[i]);
	}

	cout << nm.size() << "\n";
	for (string str : nm) {
		cout << str << "\n";
	}

	return 0;
}