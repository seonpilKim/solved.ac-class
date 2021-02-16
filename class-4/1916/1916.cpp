#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

#define MAX_SIZE 1001
#define INF INT_MAX

int N, M;
int Vertex[MAX_SIZE];
vector<pair<int, int>> Edge[MAX_SIZE];

struct compare {
	bool operator()(int v1, int v2) {
		return Vertex[v1] > Vertex[v2];
	}
};
priority_queue<int, vector<int>, compare> pq;

int Dijkstra(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	fill(Vertex, Vertex + MAX_SIZE, INF);
	for (int i = 0; i < MAX_SIZE; i++) Edge[i].clear();
	int v1, v2, price;
	while (M--) {
		cin >> v1 >> v2 >> price;
		Edge[v1].push_back(make_pair(v2, price));
	}

	int start, dest;
	cin >> start >> dest;

	Vertex[start] = 0;
	pq.push(start);

	cout << Dijkstra(dest);

	return 0;
}

int Dijkstra(int dest) {
	while (!pq.empty()) {
		int v1 = pq.top(); pq.pop();

		for (int idx = 0; idx < Edge[v1].size(); idx++) {
			int v2 = Edge[v1][idx].first;
			int weight = Edge[v1][idx].second;
			int sum = Vertex[v1] + weight;

			if (Vertex[v2] > sum) {
				Vertex[v2] = sum;
				pq.push(v2);
			}
		}
	}
	return Vertex[dest];
}