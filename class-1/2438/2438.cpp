#include <iostream>

using namespace std;

void Print__Star(int);

int main() {
	int N;

	cin >> N;

	Print__Star(N);
	
	return 0;
}

void Print__Star(int N) {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}