#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

#define INF INT_MAX

class Edge {
public:
	int v2;
	int len;
	Edge* next;

	Edge(int v2, int len) {
		this->v2 = v2;
		this->len = len;
		this->next = nullptr;
	}
};

class Vertex {
public:
	int len;
	int edges;
	Edge* head;
	Edge* tail;

	Vertex() {
		this->len = INF;
		this->edges = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void addEdge(int v2, int len) {
		Edge* newEdge = new Edge(v2, len);
		if (edges == 0) this->head = this->tail = newEdge;
		else {
			this->tail->next = newEdge;
			this->tail = newEdge;
		}
		this->edges++;
	}
};

int N, M, W;

bool Bellman_Ford(Vertex*, int);

int main() {
	int TC;
	int S, E, T;
	bool answer;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> TC;
	cin >> N >> M >> W;

	for (int i = 0; i < TC; i++) {
		Vertex* vertex = new Vertex[N + 1];
		answer = false;
		for (int j = 0; j < M; j++) {
			// 도로 입력
			cin >> S >> E >> T;
			vertex[S].addEdge(E, T);
			vertex[E].addEdge(S, T);
		}
		for (int j = 0; j < W; j++) {
			// 웜홀 입력
			cin >> S >> E >> T;
			vertex[S].addEdge(E, -T);
		}
		for (int start = 1; start <= N; start++) {
			// 모든 정점을 한 번씩 시작점으로 테스팅
			if (Bellman_Ford(vertex, start)) {
				cout << "YES\n";
				answer = true;
				break;
			}
		}
		if (!answer) cout << "NO\n";
	}

	return 0;
}
/*
	N : 지점 개수[1,500]
	M : 도로 개수[1,2500] - 무방향
	W : 웜홀 개수[1,200] - 유방향, 시작->도착 하나의 경로.
					도착하면 시작했을때보다 시간이 뒤로감
	가중치에 음의가중치가 있으므로 다익스트라 불가능.
	메모리제한도 128MB이므로, 그래프 인접리스트 구현 & 벨만포드 알고리즘 사용
	시작점 모두 적용해서 확인해야 함.
*/
bool Bellman_Ford(Vertex* vertex, int start) {
	vertex[start].len = 0;
	for (int test = 1; test < N; test++) {
		for (int v1 = 1; v1 <= N; v1++) {
			for (Edge* curEdge = vertex[v1].head; curEdge != nullptr; curEdge = curEdge->next) {
				vertex[curEdge->v2].len = min((vertex[v1].len + curEdge->len), vertex[curEdge->v2].len);
				if (vertex[start].len < 0) return true;
			}
		}
	}
	return false;
}