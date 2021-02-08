#include <iostream>
#include <vector>

using namespace std;

class Edge {
public:
	int vertex;
	int len;
	bool visited1, visited2;
	Edge(int vertex, int len) {
		this->vertex = vertex;
		this->len = len;
		this->visited1 = false;
		this->visited2 = false;
	}
};

class Node {
public:
	int vertex;
	vector<Edge> edges;

	Node() {}
	Node(int vertex) {
		this->vertex = vertex;
	}
};

Node* tree;
int sum, V;
int N, v1, v2, len;

void input();
void DFS(int, int);
void DFS2(int, int);

int main() {
	input();

	DFS(1, 0);
	DFS2(V, 0);
	cout << sum;

	return 0;
}

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	tree = new Node[N + 1];

	for (int i = 0; i < N; i++) {
		cin >> v1;
		tree[v1] = Node(v1);
		while (true) {
			cin >> v2;
			if (v2 == -1) break;
			cin >> len;
			tree[v1].edges.push_back(Edge(v2, len));
		}
	}
}

void DFS(int vertex, int len) {
	for (int i = 0; i < tree[vertex].edges.size(); i++) {
		if (!tree[vertex].edges[i].visited1) {
			if (tree[vertex].edges[i].len + len > sum) {
				sum = tree[vertex].edges[i].len + len;
				V = tree[vertex].edges[i].vertex;
			}
			tree[vertex].edges[i].visited1 = true;
			for (Edge& edge : tree[tree[vertex].edges[i].vertex].edges) {
				if (edge.vertex == vertex) edge.visited1 = true;
			}
			DFS(tree[vertex].edges[i].vertex, tree[vertex].edges[i].len + len);
		}
	}
}

void DFS2(int vertex, int len) {
	for (int i = 0; i < tree[vertex].edges.size(); i++) {
		if (!tree[vertex].edges[i].visited2) {
			if (tree[vertex].edges[i].len + len > sum) {
				sum = tree[vertex].edges[i].len + len;
				V = tree[vertex].edges[i].vertex;
			}
			tree[vertex].edges[i].visited2 = true;
			for (Edge& edge : tree[tree[vertex].edges[i].vertex].edges) {
				if (edge.vertex == vertex) edge.visited2 = true;
			}
			DFS2(tree[vertex].edges[i].vertex, tree[vertex].edges[i].len + len);
		}
	}
}