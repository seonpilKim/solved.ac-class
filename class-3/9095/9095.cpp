#include <iostream>

using namespace std;

int main() {
	int dp[11] = { 0 }; // 전역변수로 초기화없이 선언과 동일
	int n = 3, T, num;

	dp[1] = 1; dp[2] = 2; dp[3] = 4;

	while (++n < 11) {
		dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3];
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> num;
		cout << dp[num] << "\n";
	}

	return 0;
}
