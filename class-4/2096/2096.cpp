#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100000

int N;
int arr[MAX_SIZE][3];
pair<int, int> dp[3];

void move_down();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	move_down();

	return 0;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
}

void move_down() {
	input();
	pair<int, int> tmp1, tmp2, tmp3;
	dp[0].first = dp[0].second = arr[0][0];
	dp[1].first = dp[1].second = arr[0][1];
	dp[2].first = dp[2].second = arr[0][2];

	for (int i = 1; i < N; i++) {
		tmp1.first = min(dp[0].first + arr[i][0], dp[1].first + arr[i][0]);
		tmp1.second = max(dp[0].second + arr[i][0], dp[1].second + arr[i][0]);

		tmp2.first = min(min(dp[0].first + arr[i][1], dp[1].first + arr[i][1]), dp[2].first + arr[i][1]);
		tmp2.second = max(max(dp[0].second + arr[i][1], dp[1].second + arr[i][1]), dp[2].second + arr[i][1]);

		tmp3.first = min(dp[1].first + arr[i][2], dp[2].first + arr[i][2]);
		tmp3.second = max(dp[1].second + arr[i][2], dp[2].second + arr[i][2]);

		dp[0] = tmp1;
		dp[1] = tmp2;
		dp[2] = tmp3;
	}

	cout << max(max(dp[0].second, dp[1].second), dp[2].second) << " ";
	cout << min(min(dp[0].first, dp[1].first), dp[2].first);
}