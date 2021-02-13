#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>

#define INF INT_MAX
#define START 0
#define NONE -1
#define VISITED -1
#define UNVISITED -2

using namespace std;

struct compare {
	bool operator()(pair<int, int> v1, pair<int, int> v2) {
		return v1.second > v2.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
int V, E, K;
int* Vertex;
int** Edge;

void input();
void Dijkstra();

int main() {
	input();

	Dijkstra();

	return 0;
}

void input() {
	int u, v, w;
	cin >> V >> E >> K;
	Vertex = new int[V + 1];
	fill(Vertex, Vertex+V+1, INF);
	Vertex[K] = START;
	pq.push(make_pair(K, Vertex[K]));


	// 최대 30만*30만 Byte 메모리 필요 -> 메모리초과
	Edge = new int* [E + 1];
	for (int i = 0; i <= E; i++) {
		Edge[i] = new int[E + 1];
		fill(Edge[i], Edge[i] + E + 1, NONE);
	}

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		// 방향그래프
		Edge[u][v] = w;
	}
}

void Dijkstra() {
	while (!pq.empty()) {
		int v1 = pq.top().first; pq.pop();
		for (int v2 = 1; v2 <= V; v2++) {
			if (Edge[v1][v2] != NONE) {
				int sum = Edge[v1][v2] + Vertex[v1];
				if (sum < Vertex[v2]) {
					Vertex[v2] = sum;
					pq.push(make_pair(v2, Vertex[v2]));
				}
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (Vertex[i] == INF) cout << "INF\n";
		else cout << Vertex[i] << "\n";
	}
}