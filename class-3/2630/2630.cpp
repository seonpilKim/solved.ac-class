#include <iostream>
#include <cmath>

using namespace std;

int N, Sum = 0, one = 0, zero = 0;
int** arr;

int Cut(int, int, int);
void input();

int main() {
	input();

	if (Sum == (int)pow(N, 2)) one++;
	else if (Sum == 0) zero++;
	else Cut(0, 0, N);

	cout << zero << "\n" << one;

	return 0;
}

void input() {
	cin >> N;

	arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			Sum += arr[i][j];
		}
	}
}

int Cut(int x, int y, int len) {
	if (len == 1) return 0;
	int sum = 0;

	if (len == 2) {
		sum = arr[x][y] + arr[x + 1][y] + arr[x][y + 1] + arr[x + 1][y + 1];
		if (sum == 3) { one += 3; zero++; }
		else if (sum == 2) { one += 2; zero += 2; }
		else if (sum == 1) { one++; zero += 3; }
	}
	else {
		int s[4];
		s[0] = Cut(x, y, len / 2);
		s[1] = Cut(x, y + len / 2, len / 2);
		s[2] = Cut(x + len / 2, y, len / 2);
		s[3] = Cut(x + len / 2, y + len / 2, len / 2);
		sum = s[0] + s[1] + s[2] + s[3];
		if (sum != (int)pow(len, 2) && sum != 0) {
			for (int i = 0; i < 4; i++) {
				if (s[i] == (int)pow(len / 2, 2)) one++;
				else if (s[i] == 0) zero++;
			}
		}
	}
	return sum;
}