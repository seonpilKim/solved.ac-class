#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>

#define INF INT_MAX
#define START 0

using namespace std;

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
		if (edges == 0) {
			this->head = this->tail = new Edge(v2, len);
		}
		else {
			Edge* newEdge = new Edge(v2, len);
			this->tail->next = newEdge;
			this->tail = newEdge;
		}
		this->edges++;
	}
};

int V, E, K;
Vertex* vertex;
struct compare {
	bool operator()(pair<int, Vertex> v1, pair<int, Vertex> v2) {
		return v1.second.len > v2.second.len;
	}
};
priority_queue<pair<int, Vertex>, vector<pair<int, Vertex>>, compare> pq;

void input();
void Dijkstra();

int main() {
	input();

	Dijkstra();

	return 0;
}

void input() {
	int u, v, w;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E >> K;
	vertex = new Vertex[V + 1];
	vertex[K].len = START;
	pq.push(make_pair(K, vertex[K]));

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		// 방향그래프
		vertex[u].addEdge(v, w);

	}
}

void Dijkstra() {
	while (!pq.empty()) {
		int v1 = pq.top().first; pq.pop();
		if (vertex[v1].edges) {
			for (Edge* curEdge = vertex[v1].head; curEdge != nullptr; curEdge = curEdge->next) {
				int sum = curEdge->len + vertex[v1].len;
				if (sum < vertex[curEdge->v2].len) {
					vertex[curEdge->v2].len = sum;
					pq.push(make_pair(curEdge->v2, vertex[curEdge->v2]));
				}
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (vertex[i].len == INF) cout << "INF\n";
		else cout << vertex[i].len << "\n";
	}
}