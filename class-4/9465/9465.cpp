#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int stiker[2][MAX];

int findMax(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;

	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		for (int r = 0; r < 2; r++) {
			for (int c = 0; c < n; c++) {
				cin >> stiker[r][c];
			}
		}

		cout << findMax(n) << '\n';
	}

	return 0;
}

int findMax(int n) {
	int c = 0;
	int Max = 0;

	while (true) {
		if (c + 2 <= n) {
			stiker[1][c + 2] += max((stiker[0][c]), (stiker[1][c] + stiker[0][c + 1]));
			stiker[0][c + 2] += max((stiker[1][c]), (stiker[0][c] + stiker[1][c + 1]));
			c += 2;
		}
		else if (c + 1 == n) {
			stiker[1][c + 1] += stiker[0][c];
			stiker[0][c + 1] += stiker[1][c];
			break;
		}
	}

	return max(stiker[0][n - 1], stiker[1][n - 1]);
}