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

void input();
void Dijkstra();
void Dijkstra2();

struct compare {
	bool operator()(pair<int, int> v1, pair<int, int> v2) {
		return v1.second < v2.second;
	}
};

priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq;

int main() {
	input();

	Dijkstra();
	Dijkstra2();

	sort(len, len + N + 1);
	cout << len[N];

	return 0;
}

void input() {
	int v1, v2, t;

	cin >> N >> M >> X;

	len = new int[N + 1];
	memset(len, 0, sizeof(int) * (N + 1));

	V = new int[N + 1];
	fill(V, V + N + 1, INF);
	/*
		memset()�� 2��° ���ڴ� single byte�̴�.
		memset()�� �ش� �޸��� Ư����ġ�� int�� ä��� ���� �ƴ϶� single bytes�� ä���.
		int���� unsigned char������ ��ȯ�Ͽ� ä��⿡ ���� �޶��� �� ����.

		char, unsigned char�� ������ ������ 0�̿��� ������ �ʱ�ȭ�ϸ� �ȵȴ�.
		https://beautyrain.tistory.com/7 ����
		std::fill()�Լ��� �������.
	*/
	V[X] = 0;

	E = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		E[i] = new int[N + 1];
		fill(E[i], E[i] + N + 1, NONE);
	}

	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> t;
		E[v1][v2] = t;
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
}

void Dijkstra2() {
	for (int i = 1; i <= N; i++) {
		if (i != X) {
			pq.push(pair<int, int>(i, V[i]));

			for (int j = 1; j <= N; j++) {
				if (j == i) V[j] = 0;
				else V[j] = INF;
			}

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
			len[i] += V[X];
		}
	}
}
