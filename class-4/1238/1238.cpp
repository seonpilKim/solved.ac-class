#include <iostream>
#include <string.h>

using namespace std;

// 시간제한 1초
// N : 마을 수 [1,1,000]
// M : 단방향 도로 수 [1,10,000]
// X : 파티하는 마을 번호
int N, M, X, S, min;
int** graph;
int** dp;
int* visited;

void DFS(int, int);
void DFS2(int, int);
void input();

int main() {
	int max = 0, len;
	
	input();

	for (int i = 1; i <= N; i++) {
		if (i != X) {
			S = i;
			DFS(i, 0);
			memset(visited, 0, sizeof(int) * (N + 1));
			DFS2(X, 0);
			memset(visited, 0, sizeof(int) * (N + 1));
		}
	}

	for (int i = 1; i <= N; i++) {
		len = dp[i][X] + dp[X][i];
		if (i != X && len > max) max = len;
	}

	cout << max;

	return 0;
}

void input() {
	int start, dest, time;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> X;

	visited = new int[N + 1];
	memset(visited, 0, sizeof(int) * (N + 1));

	graph = new int* [N + 1];
	dp = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		graph[i] = new int[N + 1];
		memset(graph[i], -1, sizeof(int) * (N + 1));
		dp[i] = new int[N + 1];
		memset(dp[i], -1, sizeof(int) * (N + 1));
	}


	for (int i = 0; i < M; i++) {
		cin >> start >> dest >> time;
		graph[start][dest] = time;
	}
}

void DFS(int start, int len) {
	visited[start] = 1;
	for (int d = 1; d <= N; d++) {
		if (graph[start][d] != -1 && visited[d] != 1) {
			int sum = graph[start][d] + len;
			if (d == X) {
				if (dp[S][d] == -1 || dp[S][d] > sum) dp[S][d] = sum;				
			}
			else DFS(d, sum);
		}
	}
}

void DFS2(int start, int len) {
	visited[start] = 1;
	for (int d = 1; d <= N; d++) {
		if (graph[start][d] != -1 && visited[d] != 1) {
			int sum = graph[start][d] + len;
			if (d == S) {
				if (dp[X][d] == -1 || dp[X][d] > sum) dp[X][d] = sum;
			}
			else DFS2(d, sum);
		}
	}
}