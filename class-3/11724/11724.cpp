#include <iostream>
#include <string.h>

using namespace std;

int N, M;
int* node;
int cnt = 0;
int** graph;

void DFS(int);

int main() {
	int u1, u2;

	cin >> N >> M;
	node = new int[N];
	memset(node, -1, sizeof(int) * N);
	graph = new int* [N];
	for (int i = 0; i < N; i++) {
		graph[i] = new int[N];
		memset(graph[i], 0, sizeof(int) * N);
	}

	while (M--) {
		cin >> u1 >> u2;
		graph[--u1][--u2] = 1;
		graph[u2][u1] = 1;
		node[u1] = 0;
		node[u2] = 0;
	}
	
	for (int i = 0; i < N; i++) {
		if (node[i] == 0) {
			DFS(i); cnt++;
		}
		else if (node[i] == -1) cnt++;
	}

	cout << cnt;

	return 0;
}

void DFS(int u) {
	for (int i = 0; i < N; i++) {
		if (u != i && graph[u][i] == 1) {
			graph[u][i] = -1;
			graph[i][u] = -1;
			if (node[i] == 0) {
				node[i] = 1; DFS(i);
			}
		}
	}
}