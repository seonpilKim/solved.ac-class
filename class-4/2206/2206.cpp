#include <iostream>
#include <queue>

using namespace std;

#define UNVISITED 0
#define VISITED 1
#define OPEN 0
#define CLOSE 1
#define NOBREAK 0
#define BREAK 1

int N, M;
pair<int, int> Map[1000][1000][2];
queue<pair<pair<int, int>, bool>> q;
queue<pair<pair<int, int>, bool>> q2;

int BFS();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout << BFS();

	return 0;
}

void input() {
	cin >> N >> M;
	string rooms;
	for (int i = 0; i < N; i++) {
		cin >> rooms;
		for (int j = 0; j < rooms.size(); j++) {
			Map[i][j][NOBREAK].first = rooms[j] - 48;
			Map[i][j][BREAK].first = rooms[j] - 48;
		}
	}
}

int BFS() {
	input();

	int n = 0, n2, room, is;
	bool flag = false;
	q.push(make_pair(make_pair(0, 0), false));
	Map[0][0][NOBREAK].second = VISITED;
	Map[0][0][BREAK].second = VISITED;

	while (!q.empty()) {

		while(!q.empty()) {
			q2.push(q.front()); q.pop();
		}

		while (!q2.empty()) {
			pair<int, int> xy = q2.front().first;
			int x = xy.first;
			int y = xy.second;

			if (x == N - 1 && y == M - 1) return ++n;
			bool isbroken = q2.front().second;

			if (x > 0) {
				if (isbroken == false && Map[x - 1][y][NOBREAK].second == UNVISITED) {
					if (Map[x - 1][y][NOBREAK].first == OPEN) {
						q.push(make_pair(make_pair(x - 1, y), isbroken));
						Map[x - 1][y][NOBREAK].second = VISITED;
					}
					else if (Map[x - 1][y][NOBREAK].first == CLOSE) {
						q.push(make_pair(make_pair(x - 1, y), true));
						Map[x - 1][y][BREAK].second = VISITED;
					}
				}
				else if (isbroken == true && Map[x - 1][y][BREAK].second == UNVISITED) {
					if (Map[x - 1][y][BREAK].first == OPEN) {
						q.push(make_pair(make_pair(x - 1, y), isbroken));
						Map[x - 1][y][BREAK].second = VISITED;
					}
				}
			}
			if (x < N - 1) {
				if (isbroken == false && Map[x + 1][y][NOBREAK].second == UNVISITED) {
					if (Map[x + 1][y][NOBREAK].first == OPEN) {
						q.push(make_pair(make_pair(x + 1, y), isbroken));
						Map[x + 1][y][NOBREAK].second = VISITED;
					}
					else if (Map[x + 1][y][NOBREAK].first == CLOSE) {
						q.push(make_pair(make_pair(x + 1, y), true));
						Map[x + 1][y][BREAK].second = VISITED;
					}
				}
				else if (isbroken == true && Map[x + 1][y][BREAK].second == UNVISITED) {
					if (Map[x + 1][y][BREAK].first == OPEN) {
						q.push(make_pair(make_pair(x + 1, y), isbroken));
						Map[x + 1][y][BREAK].second = VISITED;
					}
				}
			}
			if (y > 0) {
				if (isbroken == false && Map[x][y - 1][NOBREAK].second == UNVISITED) {
					if (Map[x][y - 1][NOBREAK].first == OPEN) {
						q.push(make_pair(make_pair(x, y - 1), isbroken));
						Map[x][y - 1][NOBREAK].second = VISITED;
					}
					else if (Map[x][y - 1][NOBREAK].first == CLOSE) {
						q.push(make_pair(make_pair(x, y - 1), true));
						Map[x][y - 1][BREAK].second = VISITED;
					}
				}
				else if (isbroken == true && Map[x][y - 1][BREAK].second == UNVISITED) {
					if (Map[x][y - 1][BREAK].first == OPEN) {
						q.push(make_pair(make_pair(x, y - 1), isbroken));
						Map[x][y - 1][BREAK].second = VISITED;
					}
				}
			}
			if (y < M - 1) {
				if (isbroken == false && Map[x][y + 1][NOBREAK].second == UNVISITED) {
					if (Map[x][y + 1][NOBREAK].first == OPEN) {
						q.push(make_pair(make_pair(x, y + 1), isbroken));
						Map[x][y + 1][NOBREAK].second = VISITED;
					}
					else if (Map[x][y + 1][NOBREAK].first == CLOSE) {
						q.push(make_pair(make_pair(x, y + 1), true));
						Map[x][y + 1][BREAK].second = VISITED;
					}
				}
				else if (isbroken == true && Map[x][y + 1][BREAK].second == UNVISITED) {
					if (Map[x][y + 1][BREAK].first == OPEN) {
						q.push(make_pair(make_pair(x, y + 1), isbroken));
						Map[x][y + 1][BREAK].second = VISITED;
					}
				}
			}		
			q2.pop();
		}

		n++;
	}

	return -1;
}