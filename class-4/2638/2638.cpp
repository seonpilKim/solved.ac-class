#include <iostream>
#include <queue>

#define MAX 101
#define UNVISITED 0
#define VISITED 1
#define INIT 0
#define AIR -1
#define MELTING -1
#define CHEESE 1

using namespace std;

int N, M;
pair<int,int> paper[MAX][MAX];
queue<pair<int, int>> q;
queue<pair<int, int>> q2;

int getTime();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int input;
			cin >> input;
			paper[i][j] = make_pair(input, UNVISITED);
		}
	}
	
	cout << getTime();
	
	return 0;
}

int getTime() {
	int time = 0;

	while (true) {

		/*
			Classifing the air outside the cheese and the air inside it
		*/
		q.push(make_pair(1, 1));
		paper[1][1].second = VISITED;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			q2.push(make_pair(x, y));

			if (x > 1 && paper[x - 1][y].first <= INIT && paper[x - 1][y].second == UNVISITED) {
				q.push(make_pair(x - 1, y));
				paper[x - 1][y] = make_pair(AIR, VISITED);
			}
			if (x < N && paper[x + 1][y].first <= INIT && paper[x + 1][y].second == UNVISITED) {
				q.push(make_pair(x + 1, y));
				paper[x + 1][y] = make_pair(AIR, VISITED);
			}
			if (y > 1 && paper[x][y - 1].first <= INIT && paper[x][y - 1].second == UNVISITED) {
				q.push(make_pair(x, y - 1));
				paper[x][y - 1] = make_pair(AIR, VISITED);
			}
			if (y < M && paper[x][y + 1].first <= INIT && paper[x][y + 1].second == UNVISITED) {
				q.push(make_pair(x, y + 1));
				paper[x][y + 1] = make_pair(AIR, VISITED);
			}
		}

		/* 
			Initializing the state of visit
		*/
		while (!q2.empty()) {
			int x = q2.front().first;
			int y = q2.front().second;
			q2.pop();

			paper[x][y].second = UNVISITED;
		}

		/* 
			Find cheeses
		*/
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (paper[i][j].first == CHEESE) q.push(make_pair(i, j));
			}
		}

		/* 
			Find meltable cheeses
		*/
		bool isCheese = false;
		while (!q.empty()) {
			int contacts = 0;
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x > 1 && paper[x - 1][y].first == AIR) contacts++;
			if (x < N && paper[x + 1][y].first == AIR) contacts++;
			if (y > 1 && paper[x][y - 1].first == AIR) contacts++;
			if (y < M && paper[x][y + 1].first == AIR) contacts++;

			if (contacts >= 2) q2.push(make_pair(x, y));							
			else isCheese = true;
		}
		time++;

		/* 
			Escape condition from infinity loop
			: no more cheese
		*/
		if (!isCheese) return time;

		/*
			Melting cheeses
		*/
		while (!q2.empty()) {
			int x = q2.front().first;
			int y = q2.front().second;
			q2.pop();
			paper[x][y].first = MELTING;
		}
	}
}