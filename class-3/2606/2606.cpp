#include <iostream>
#include <vector>
using namespace std;

class PC {
public:
	int number;
	vector<PC*> network;
	bool visited;

	PC() {}
	PC(int number) {
		this->number = number;
		this->visited = false;
	}
};

class Network {
public:
	PC* computers;
	int count;

	Network(int n) {
		computers = new PC[n + 1];
		computers[0] = NULL;
		for (int i = 1; i < n + 1; i++) {
			computers[i] = PC(i);
		}
		this->count = 0;
	}

	void Link(int pc1, int pc2) {
		computers[pc1].network.push_back(&computers[pc2]);
		computers[pc2].network.push_back(&computers[pc1]);
	}

	void DFS() {
		for (int i = 0; i < computers[1].network.size(); i++) {
			if (computers[1].network[i]->visited == false) {
				this->count++;
				computers[1].network[i]->visited = true;
				DFS(computers[1].network[i]);
			}
		}
	}

	void DFS(PC* pc) {
		for (int i = 0; i < pc->network.size(); i++) {
			if (pc->network[i]->visited == false && pc->network[i]->number != 1) {
				this->count++;
				pc->network[i]->visited = true;
				DFS(pc->network[i]);
			}
		}
	}
};

int main() {
	int N, M, pc1, pc2;

	cin >> N;
	Network network(N);
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> pc1 >> pc2;
		network.Link(pc1, pc2);
	}
	
	network.DFS();
	cout << network.count;

	return 0;
}