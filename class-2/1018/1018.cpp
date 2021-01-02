#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int M, N;
	int min = 64, cnt1, cnt2;
	char** chess;

	cin >> M >> N;
	chess = new char* [M];
	for (int i = 0; i < M; i++) {
		chess[i] = new char[N];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> chess[i][j];
		}
	}

	for (int i = 0; i < M - 7; i++) {
		for (int j = 0; j < N - 7; j++) {

			cnt1 = cnt2 = 0;

			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if ((k + l) % 2 == 0) {
						if (chess[k][l] == 'W') cnt1++;
						else cnt2++;
					}
					else {
						if (chess[k][l] == 'B') cnt1++;
						else cnt2++;
					}
				}
			}

			min = (min < cnt1 ? min : cnt1);
			min = (min < cnt2 ? min : cnt2);
		}
	}

	cout << min;

	return 0;
}
