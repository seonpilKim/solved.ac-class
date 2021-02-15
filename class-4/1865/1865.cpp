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
			// ���� �Է�
			cin >> S >> E >> T;
			vertex[S].addEdge(E, T);
			vertex[E].addEdge(S, T);
		}
		for (int j = 0; j < W; j++) {
			// ��Ȧ �Է�
			cin >> S >> E >> T;
			vertex[S].addEdge(E, -T);
		}
		for (int start = 1; start <= N; start++) {
			// ��� ������ �� ���� ���������� �׽���
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
	N : ���� ����[1,500]
	M : ���� ����[1,2500] - ������
	W : ��Ȧ ����[1,200] - ������, ����->���� �ϳ��� ���.
					�����ϸ� �������������� �ð��� �ڷΰ�
	����ġ�� ���ǰ���ġ�� �����Ƿ� ���ͽ�Ʈ�� �Ұ���.
	�޸����ѵ� 128MB�̹Ƿ�, �׷��� ��������Ʈ ���� & �������� �˰��� ���
	������ ��� �����ؼ� Ȯ���ؾ� ��.
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