#include <iostream>
#include <queue>

using namespace std;

#define UNVISITED 0
#define VISITED 1
#define OPEN 0
#define CLOSE 1

int N, M;
pair<int, int> Map[1000][1000];
queue<pair<pair<int, int>, bool>> q;
queue<pair<pair<int, int>, bool>> q2;

int BFS();

int main() {
	/*ios_base::sync_with_stdio(false);
	cin.tie(nullptr);*/
	
	cout << BFS();

	return 0;
}

void input() {
	cin >> N >> M;
	string rooms;
	for (int i = 0; i < N; i++) {
		cin >> rooms;
		for (int j = 0; j < rooms.size(); j++) {
			Map[i][j].first = rooms[j] - 48;
			Map[i][j].second = UNVISITED;
		}
	}
}

int BFS() {
	input();

	int n = 0, n2, room, is;
	bool flag = false;
	q.push(make_pair(make_pair(0, 0), false));
	while (!q.empty()) {

		while(!q.empty()) {
			q2.push(q.front()); q.pop();
		}

		while (!q2.empty()) {
			pair<int, int> xy = q2.front().first;
			int x = xy.first;
			int y = xy.second;

			if (Map[x][y].second == UNVISITED) {
				if (x == N - 1 && y == M - 1) return ++n;
				Map[x][y].second = VISITED;
				bool isbroken = q2.front().second;

				if (x > 0) {
					if (Map[x - 1][y].second == UNVISITED) {
						if (Map[x - 1][y].first == OPEN) q.push(make_pair(make_pair(x - 1, y), isbroken));
						else if (isbroken == false && Map[x - 1][y].first == CLOSE) {
							q.push(make_pair(make_pair(x - 1, y), true));
						}
					}
				}
				if (x < N - 1) {
					if (Map[x + 1][y].second == UNVISITED) {
						if (Map[x + 1][y].first == OPEN) q.push(make_pair(make_pair(x + 1, y), isbroken));
						else if (isbroken == false && Map[x + 1][y].first == CLOSE) {
							q.push(make_pair(make_pair(x + 1, y), true));
						}
					}
				}
				if (y > 0) {
					if (Map[x][y - 1].second == UNVISITED) {
						if (Map[x][y - 1].first == OPEN) q.push(make_pair(make_pair(x, y - 1), isbroken));
						else if (isbroken == false && Map[x][y - 1].first == CLOSE) {
							q.push(make_pair(make_pair(x, y - 1), true));
						}
					}
				}
				if (y < M - 1) {
					if (Map[x][y + 1].second == UNVISITED) {
						if (Map[x][y + 1].first == OPEN) q.push(make_pair(make_pair(x, y + 1), isbroken));
						else if (isbroken == false && Map[x][y + 1].first == CLOSE) {
							q.push(make_pair(make_pair(x, y + 1), true));
						}
					}
				}
			}
			q2.pop();
		}

		n++;
	}

	return -1;
}