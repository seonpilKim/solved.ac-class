#include <iostream>

using namespace std;

bool Is__PrimeNumber(int);

int main() {
	int T, N, cnt = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		if (Is__PrimeNumber(N)) cnt++;
	}
	
	cout << cnt;

	return 0;
}

bool Is__PrimeNumber(int N) {
	if (N == 2) return true;
	else if (N < 2 || N % 2 == 0) return false;

	for (int i = 3; i < N; i += 2) {
		if (N % i == 0) return false;
	}
	return true;
}