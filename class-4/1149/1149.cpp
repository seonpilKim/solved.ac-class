#include <iostream>
#include <algorithm>

using namespace std;

#define R 0
#define G 1
#define B 2

int min(int, int);
int min(int, int, int);

int main() {
	int N;
	int** dp;

	cin >> N;
	dp = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		dp[i] = new int[3];
	}
	dp[0][R] = dp[0][G] = dp[0][B] = 0;
	
	for (int i = 1; i <= N; i++) {
		cin >> dp[i][R];
		cin >> dp[i][G];
		cin >> dp[i][B];
		
		dp[i][R] += min(dp[i - 1][G], dp[i - 1][B]);
		dp[i][G] += min(dp[i - 1][R], dp[i - 1][B]);
		dp[i][B] += min(dp[i - 1][G], dp[i - 1][R]);
	}

	cout << min(dp[N][R], dp[N][G], dp[N][B]);

	return 0;
}

int min(int a, int b) {
	return a < b ? a : b;
}


int min(int a, int b, int c) {
	int arr[] = { a,b,c };
	sort(arr, arr + 3);
	return arr[0];
}