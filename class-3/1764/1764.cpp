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
		idx = lower_bound(n.begin(), n.end(), input) - n.begin();
		if (i == 0) n.push_back(input);
		else if (idx < n.size() && n[idx] != input || idx == n.size()) {
			n.push_back(input);
			sort(n.begin(), n.end());
		}
	}


	for (int i = 0; i < M; i++) {
		cin >> input;
		idx = lower_bound(m.begin(), m.end(), input) - m.begin();
		if (i == 0) {
			m.push_back(input);
			idx = lower_bound(n.begin(), n.end(), input) - n.begin();
			if ((idx < n.size() && n[idx] == input)) nm.push_back(input);
		}
		else if (idx < m.size() && m[idx] != input || idx == m.size()) {
			m.push_back(input);
			sort(m.begin(), m.end());
			idx = lower_bound(n.begin(), n.end(), input) - n.begin();
			if ((idx < n.size() && n[idx] == input)) nm.push_back(input);
		}
	}

	cout << nm.size() << "\n";
	for (string str : nm) {
		cout << str << "\n";
	}

	return 0;
}