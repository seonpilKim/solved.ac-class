#include <iostream>
#include <queue>

#define MAX 101
#define VISITED 2
#define AIR 0
#define CHEESE 1
#define MELTING -1
#define INIT true

using namespace std;

int N, M;
int paper[MAX][MAX];
queue<pair<int, int>> q;

int getTime();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> paper[i][j];
		}
	}
	
	cout << getTime();
	
	return 0;
}

int getTime() {
	int time = 0;
	bool all_melting;
	queue<pair<int, int>> q2;
	queue<pair<int, int>> q3;
	queue<pair<int, int>> q4;

	while (true) {
		all_melting = INIT;
		q2.push(make_pair(1, 1));

		while (!q2.empty()) {
			int x = q2.front().first;
			int y = q2.front().second;
			q2.pop();
			paper[x][y] = VISITED;
			q3.push(make_pair(x, y));

			if (x > 1 && paper[x - 1][y] <= AIR) q2.push(make_pair(x - 1, y));
			if (N > x && paper[x + 1][y] <= AIR) q2.push(make_pair(x + 1, y));
			if (y > 1 && paper[x][y - 1] <= AIR) q2.push(make_pair(x, y - 1));
			if (N > y && paper[x][y + 1] <= AIR) q2.push(make_pair(x, y + 1));
		}

		while (!q3.empty()) {
			int x = q3.front().first;
			int y = q3.front().second;
			q3.pop();
			paper[x][y] = MELTING;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (paper[i][j] == CHEESE) q.push(make_pair(i, j));
			}
		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int contacts = 0;

			if (x > 1 && paper[x - 1][y] == MELTING) contacts++;
			if (N > x && paper[x + 1][y] == MELTING) contacts++;
			if (y > 1 && paper[x][y - 1] == MELTING) contacts++;
			if (N > y && paper[x][y + 1] == MELTING) contacts++;

			if (contacts > 1) q4.push(make_pair(x, y));
		}

		while (!q4.empty()) {
			int x = q4.front().first;
			int y = q4.front().second;
			q4.pop();
			paper[x][y] = MELTING;
		}
		time++;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (paper[i][j] == CHEESE) {
					all_melting = false;
					break;
				}
			}
			if (!all_melting) break;
		}
		if (all_melting) return time;
	}
}