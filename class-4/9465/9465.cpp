#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int stiker[2][MAX];
int dp[2][MAX];

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
		for (int c = 1; c <= n; c++) {
			cin >> stiker[r][c];
		}
	}

	return n;
}

int findMax() {
	int n = input();

	if (n == 1) return max(stiker[0][1], stiker[1][1]);

	dp[0][1] = stiker[0][1];
	dp[1][1] = stiker[1][1];

	for (int i = 2; i <= n; i++) {
		dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + stiker[0][i];
		dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + stiker[1][i];
	}

	return max(dp[0][n], dp[1][n]);
}