#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define INF INT_MAX
#define NONE -1
#define UNVISITED -1
#define VISITED -2
#define NOPATH -1

int N, E, V1, V2;
int len = 0, len2 = 0;
int* Vertex;
int** Edge;

void input();
void Dijkstra(int, int, int);

struct compare {
	bool operator()(pair<int, int> v1, pair<int, int> v2) {
		return v1.second > v2.second;
	}
};

priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq;

int main() {
	input();

	Dijkstra(1, V1, 1);
	if (len != NOPATH) Dijkstra(V1, V2, 1);
	if (len != NOPATH) Dijkstra(V2, N, 1);

	Dijkstra(1, V2, 2);
	if (len2 != NOPATH) Dijkstra(V2, V1, 2);
	if (len2 != NOPATH) Dijkstra(V1, N, 2);

	cout << min(len, len2);

	return 0;
}

void input() {
	int v1, v2, c;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> E;

	Vertex = new int[N + 1];

	Edge = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		Edge[i] = new int[N + 1];
		fill(Edge[i], Edge[i] + N + 1, NONE);
	}

	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2 >> c;
		Edge[v1][v2] = Edge[v2][v1] = c;
	}

	cin >> V1 >> V2;
}

void Dijkstra(int start, int end, int Case) {
	fill(Vertex, Vertex + N + 1, INF);
	Vertex[start] = 0;
	pq.push(pair<int, int>(start, Vertex[start]));

	while (!pq.empty()) {
		int vertex = pq.top().first; pq.pop();
		for (int v = 1; v <= N; v++) {
			if (Edge[vertex][v] != NONE) {
				if (Vertex[vertex] + Edge[vertex][v] < Vertex[v]) {
					Vertex[v] = Vertex[vertex] + Edge[vertex][v];
					if (v != end) pq.push(pair<int, int>(v, Vertex[v]));
				}
			}
		}
	}
	if (Case == 1) {
		if (Vertex[end] == INF) len = NOPATH;
		else len += Vertex[end];
	}
	else if (Case == 2) {
		if (Vertex[end] == INF) len2 = NOPATH;
		else len2 += Vertex[end];
	}
}

