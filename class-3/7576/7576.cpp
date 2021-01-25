#include <iostream>
#include <queue>

using namespace std;

class Tomato {
public:
	int n;
	int x;
	int y;
	bool visited;

	Tomato(){}
	Tomato(int n, int x, int y) {
		this->n = n;
		this->x = x;
		this->y = y;
		this->visited = false;
	}
};

class Box {
public:
	Tomato** xy;
	
	Box(){}
	Box(int N, int M) {
		xy = new Tomato * [N];
		for (int i = 0; i < N; i++) {
			xy[i] = new Tomato[M];
		}
	}
};

int N, M, total, days = 0;
queue<Tomato> q, preq;
Box* box;

void input();
int getDays();

int main() {
	input();

	cout << getDays();

	return 0;
}

void input() {
	int n;
	cin >> M >> N;
	
	total = N * M;
	box = new Box(N, M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> n;
			box->xy[i][j] = Tomato(n, i, j);
			if (n == -1) total--;
		}

	}
}

int getDays() {
	int n = 0;
	bool infect;

	// 초기 익은 토마토 큐에 추가
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box->xy[i][j].n == 1) {
				q.push(box->xy[i][j]);
				n++;
			}
		}
	}

	while (true) {
		infect = false;

		// BFS
		while (!q.empty()) {
			Tomato cur = q.front(); q.pop();
			if (cur.y + 1 < M && box->xy[cur.x][cur.y + 1].n == 0) { 
				box->xy[cur.x][cur.y + 1].n = 1; 
				infect = true; 
				preq.push(box->xy[cur.x][cur.y + 1]); 
				n++;
			}
			if (cur.x + 1 < N && box->xy[cur.x + 1][cur.y].n == 0) { 
				box->xy[cur.x + 1][cur.y].n = 1; 
				infect = true; 
				preq.push(box->xy[cur.x + 1][cur.y]);
				n++;
			}
			if (cur.y - 1 >= 0 && box->xy[cur.x][cur.y - 1].n == 0) { 
				box->xy[cur.x][cur.y - 1].n = 1; 
				infect = true; 
				preq.push(box->xy[cur.x][cur.y - 1]);
				n++;
			}
			if (cur.x - 1 >= 0 && box->xy[cur.x - 1][cur.y].n == 0) { 
				box->xy[cur.x - 1][cur.y].n = 1; 
				infect = true; 
				preq.push(box->xy[cur.x - 1][cur.y]);
				n++;
			}
		}

		while (!preq.empty()) { q.push(preq.front()); preq.pop(); }
		if (infect) days++;
		if (q.empty()) break;
	}

	// 익지않은 토마토가 있는지 판별
	if (n != total) return -1;

	return days;
}