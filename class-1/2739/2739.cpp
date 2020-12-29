#include <iostream>

using namespace std;

void Multiple(int);

int main() {
	int N;

	cin >> N;

	Multiple(N);

	return 0;
}

void Multiple(int N) {
	for (int i = 1; i < 10; i++) {
		cout << N << " * " << i << " = " << N * i << "\n";
	}
}


