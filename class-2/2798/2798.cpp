#include <iostream>

using namespace std;

int Find__cards(int*, int, int);

int main() {
	int N, M;
	int* cards;

	cin >> N >> M;
	cards = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}

	cout << Find__cards(cards, N, M);

	return 0;
}

int Find__cards(int* cards, int N, int M) {
	int sum__3cards = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (cards[i] + cards[j] + cards[k] <= M) {
					if (cards[i] + cards[j] + cards[k] > sum__3cards) 
						sum__3cards = cards[i] + cards[j] + cards[k];
				}
			}
		}
	}
	return sum__3cards;
}