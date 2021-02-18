#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100000
#define MIN 0
#define MAX 1

int N;
int** arr;
int dp[MAX_SIZE][2];

void move_down(int, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[3];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	move_down(0, 0 ,0);
	move_down(0, 1 ,0);
	move_down(0, 2, 0);

	cout << dp[N - 1][MAX] << " " << dp[N - 1][MIN];

	return 0;
}

void move_down(int h, int w, int val) {
	int value = arr[h][w] + val;

	if (dp[h][MIN] == 0) dp[h][MIN] = value;
	else dp[h][MIN] = min(dp[h][MIN], value);
	if (dp[h][MAX] == 0) dp[h][MAX] = value;
	else dp[h][MAX] = max(dp[h][MAX], value);

	if (h < N - 1) {
		if (w == 0) {
			move_down(h + 1, w, value);
			move_down(h + 1, w + 1, value);
		}
		else if (w == 1) {
			move_down(h + 1, w - 1, value);
			move_down(h + 1, w, value);
			move_down(h + 1, w + 1, value);
		}
		else if (w == 2) {
			move_down(h + 1, w - 1, value);
			move_down(h + 1, w, value);
		}
	}
}