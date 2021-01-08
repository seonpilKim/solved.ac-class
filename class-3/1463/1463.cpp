#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int dp[1000001];

int Make_N_ONE(int);

int main() {
	int N;

	cin >> N;

	cout << Make_N_ONE(N);

	return 0;
}

int Make_N_ONE(int N) {
	int r1 = INT_MAX, r2 = INT_MAX, r3 = INT_MAX;

	if (N == 1) return 0;
	if (dp[N] > 0) return dp[N];
	
	if (N % 3 == 0) r1 = Make_N_ONE(N / 3) + 1;
	if (N % 2 == 0) r2 = Make_N_ONE(N / 2) + 1;
	r3 = Make_N_ONE(N - 1) + 1;

	return dp[N] = min({ r1, r2, r3 });
}