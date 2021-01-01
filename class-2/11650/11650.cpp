#include <iostream>
#include <algorithm>

using namespace std;

class Coordinates {
public:
	int x;
	int y;

	Coordinates() {
		this->x = 0;
		this->y = 0;
	}

	Coordinates(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

bool sortXY(Coordinates, Coordinates);

int main() {
	int N;
	int x, y;
	Coordinates* v;

	cin >> N;
	v = new Coordinates[N];

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v[i] = Coordinates(x, y);
	}

	sort(v, v+N, sortXY);

	for (int i = 0; i < N; i++) {
		cout << v[i].x << " " << v[i].y << "\n";
	}

	return 0;
}

bool sortXY(Coordinates p1, Coordinates p2) {
	return (p1.x == p2.x) ? (p1.y < p2.y) : (p1.x < p2.x);
}
