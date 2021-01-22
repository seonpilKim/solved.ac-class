#include <iostream>

using namespace std;

int N, one = 0, zero = 0;
int** arr;

void Cut(int, int, int);

int main() {
	cin >> N;

	arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	Cut(0, 0, N);

	cout << one << "\n" << zero;

	return 0;
}

void Cut(int x, int y, int len) {
	
	if (len == 2) {
		int sum = arr[x][y] + arr[x + 1][y] + arr[x][y + 1] + arr[x + 1][y + 1];
		if (sum == 4) one++;
		else if (sum == 0) zero++;
	}
	else {
		Cut(x, y, len / 2);
		Cut(x, y + len / 2, len / 2);
		Cut(x + len / 2, y, len / 2);
		Cut(x + len / 2, y + len / 2, len / 2);
	}
}