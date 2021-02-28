#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 1001

using namespace std;

char str1[MAX], str2[MAX];
char dp[MAX][MAX];

int LCS();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str1 >> str2;

	cout << LCS();

	return 0;
}

int LCS() {
	int size_str1, size_str2;
	size_str1 = strlen(str1);
	size_str2 = strlen(str2);

	for (int i = 1; i <= size_str1; i++) {
		for (int j = 1; j <= size_str2; j++) {
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	return dp[size_str1][size_str2];
}