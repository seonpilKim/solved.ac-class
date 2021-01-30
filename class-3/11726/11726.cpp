#include <iostream>

using namespace std;

int main() {
	int N;
	int dp[1001];

	dp[1] = 1;
	dp[2] = 2;

	cin >> N;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[N];

	return 0;
}



