#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

#define START 0
#define INF INT_MAX
#define MAX_SIZE 10001

int N;
int Vertex[MAX_SIZE];
vector<pair<int, int>> Edge[MAX_SIZE];

struct compare {
	bool operator()(int v1, int v2) {
		return Vertex[v1] > Vertex[v2];
	}
};
priority_queue<int, vector<int>, compare> pq;

void input();
int Dijkstra();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << Dijkstra();

	return 0;
}

void input() {
	cin >> N;

	int v1, v2, len;
	for (int i = 1; i <= N - 1; i++) {
		cin >> v1 >> v2 >> len;
		Edge[v1].push_back(make_pair(v2, len));
		Edge[v2].push_back(make_pair(v1, len));
	}
}

int Dijkstra() {
	input();

	int max = 0, max_idx;
	fill(Vertex, Vertex + MAX_SIZE, INF);
	Vertex[1] = START;
	pq.push(1);

	// root node에서 가장 먼 node 찾기
	while (!pq.empty()) {
		int v1 = pq.top(); pq.pop();

		for (int idx = 0; idx < Edge[v1].size(); idx++) {
			int v2 = Edge[v1][idx].first;
			int weight = Edge[v1][idx].second;
			int sum = Vertex[v1] + weight;

			if (Vertex[v2] > sum) {
				Vertex[v2] = sum;
				pq.push(v2);
				if (max < Vertex[v2]) {
					max = Vertex[v2];
					max_idx = v2;
				}
			}
		}
	}

	fill(Vertex, Vertex + MAX_SIZE, INF);
	Vertex[max_idx] = START;
	pq.push(max_idx);

	// tree diameter 찾기
	while (!pq.empty()) {
		int v1 = pq.top(); pq.pop();

		for (int idx = 0; idx < Edge[v1].size(); idx++) {
			int v2 = Edge[v1][idx].first;
			int weight = Edge[v1][idx].second;
			int sum = Vertex[v1] + weight;

			if (Vertex[v2] > sum) {
				Vertex[v2] = sum;
				pq.push(v2);
				if (max < Vertex[v2]) max = Vertex[v2];
			}
		}
	}

	return max;
}