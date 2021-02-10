#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define INF INT_MAX
#define NONE -1

int N, M, X;
int* len;
int* V;
int** E;
int** reverse_E;

void input();
void Dijkstra();

struct compare {
	bool operator()(pair<int, int> v1, pair<int, int> v2) {
		return v1.second < v2.second;
	}
};

priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq;

int main() {
	input();

	Dijkstra();

	sort(len, len + N + 1);
	cout << len[N];

	return 0;
}

void input() {
	int v1, v2, t;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> X;

	len = new int[N + 1];
	memset(len, 0, sizeof(int) * (N + 1));

	V = new int[N + 1];
	fill(V, V + N + 1, INF);
	V[X] = 0;

	E = new int* [N + 1];
	reverse_E = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		E[i] = new int[N + 1];
		reverse_E[i] = new int[N + 1];
		fill(reverse_E[i], reverse_E[i] + N + 1, NONE);
		fill(E[i], E[i] + N + 1, NONE);
	}

	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> t;
		E[v1][v2] = t;
		reverse_E[v2][v1] = t;
	}
}

void Dijkstra() {
	pq.push(pair<int, int>(X, V[X]));

	while (!pq.empty()) {
		int vertex = pq.top().first; pq.pop();
		for (int v = 1; v <= N; v++) {
			if (E[vertex][v] != NONE) {
				if (V[vertex] + E[vertex][v] < V[v]) {
					V[v] = V[vertex] + E[vertex][v];
					pq.push(pair<int, int>(v, V[v]));
				}
			}
		}
	}
	for (int v = 1; v <= N; v++) {
		len[v] += V[v];
	}

	fill(V, V + N + 1, INF);
	V[X] = 0;

	pq.push(pair<int, int>(X, V[X]));

	while (!pq.empty()) {
		int vertex = pq.top().first; pq.pop();
		for (int v = 1; v <= N; v++) {
			if (reverse_E[vertex][v] != NONE) {
				if (V[vertex] + reverse_E[vertex][v] < V[v]) {
					V[v] = V[vertex] + reverse_E[vertex][v];
					pq.push(pair<int, int>(v, V[v]));
				}
			}
		}
	}
	for (int v = 1; v <= N; v++) {
		len[v] += V[v];
	}
}

