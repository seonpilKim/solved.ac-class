#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N, num, len;

vector<pair<int, int>> sequence;
vector<int> subseq;
stack<int> s;

void input();
void LIS();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	LIS();

	return 0;
}

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num;
		sequence.push_back(make_pair(num, 0));
	}
}

void LIS() {
	input();

	for (int i = 0; i < N; i++) {
		int idx = lower_bound(subseq.begin(), subseq.end(), sequence[i].first) - subseq.begin();
		if (idx == subseq.size()) subseq.push_back(sequence[i].first);
		else subseq[idx] = sequence[i].first;
		sequence[i].second = idx + 1;
		len = max(len, idx + 1);
	}

	cout << len << "\n";
	for (int i = N - 1; i >= 0; i--) {
		if (sequence[i].second == len) {
			len--;
			s.push(sequence[i].first);
		}
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}