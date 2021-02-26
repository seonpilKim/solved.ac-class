#include <iostream>

using namespace std;

int N;
char** star;
void Star(int, int, int);
void Print();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	star = new char* [N + 1];
	for (int i = 0; i <= N; i++) {
		star[i] = new char[2 * N];
		fill(star[i], star[i] + 2 * N, ' ');
	}

	Star(N, 1, N);
	Print();

	return 0;
}

void Print() {
	for (int h = 1; h <= N; h++) {
		for (int idx = 1; idx < 2 * N; idx++) {
			cout << star[h][idx];
		}
		cout << '\n';
	}
}

void Star(int n, int height, int start) {
	int left, right, down;
	int h = height;
	int s = start;

	if (n == 3) {
		star[h][s] = '*';
		star[h + 1][s - 1] = star[h + 1][s + 1] = '*';
		star[h + 2][s - 2] = star[h + 2][s - 1] = star[h + 2][s] = star[h + 2][s + 1] = star[h + 2][s + 2] = '*';
		return;
	}
	
	left = s - (n / 2);
	right = s + (n / 2);
	down = h + (n / 2);

	Star(n / 2, h, s);
	Star(n / 2, down, left);
	Star(n / 2, down, right);
}