#include <iostream>
#include <vector>

using namespace std;

#define INF 2000000000
#define MAX_SIZE 501
#define START 1

int N, M, W;

bool Bellman_Ford(int*, vector<pair<int, int>>*);

int main() {
	int TC;
	int S, E, T;
	int Vertex[MAX_SIZE];
	vector<pair<int, int>> Edge[MAX_SIZE];

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		cin >> N >> M >> W;

		// 초기화
		fill(Vertex, Vertex + N + 1, INF);
		Vertex[START] = 0;
		for (int i = 1; i <= N; i++) Edge[i].clear();

		// 도로 입력
		for (int j = 0; j < M; j++) {
			cin >> S >> E >> T;
			Edge[S].push_back(make_pair(E, T));
			Edge[E].push_back(make_pair(S, T));
		}

		// 웜홀 입력
		for (int j = 0; j < W; j++) {
			cin >> S >> E >> T;
			Edge[S].push_back(make_pair(E, -T));
		}

		// 벨만-포드 알고리즘
		if (Bellman_Ford(Vertex, Edge)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}

bool Bellman_Ford(int* vertex, vector<pair<int, int>>* edge) {
	for (int test = 1; test <= N; test++) {
		for (int v1 = 1; v1 <= N; v1++) {
			for (int idx = 0; idx < edge[v1].size(); idx++) {
				int v2 = edge[v1][idx].first;
				int weight = edge[v1][idx].second;

				if (vertex[v2] > (vertex[v1] + weight)) {
					vertex[v2] = vertex[v1] + weight;

					if (test == N) return true;
				}
			}
		}
	}
	if(vertex[START] < 0) return true;
	return false;
}