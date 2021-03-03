#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int stiker[2][MAX];

int findMax();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;

	while (T--) cout << findMax() << '\n';

	return 0;
}

int input() {
	int n;
	cin >> n;

	for (int r = 0; r < 2; r++) {
		for (int c = 0; c < n; c++) {
			cin >> stiker[r][c];
		}
	}

	return n;
}

int findMax() {
	int n = input();
	int c = 0;

	if (n == 1) return max(stiker[0][0], stiker[1][0]);

	while (true) {
		if (c + 2 < n) {
			stiker[1][c + 2] += max((stiker[0][c]), (stiker[1][c] + stiker[0][c + 1]));
			stiker[0][c + 2] += max((stiker[1][c]), (stiker[0][c] + stiker[1][c + 1]));
			c += 2;

			if (c == n - 1) break;
		}
		else if (c + 1 == n - 1) {
			stiker[1][c + 1] += stiker[0][c];
			stiker[0][c + 1] += stiker[1][c];
			break;
		}
	}

	return max(stiker[0][n - 1], stiker[1][n - 1]);
}