#include <iostream>

using namespace std;

void Sum(string);

int main() {
	int T;
	string N;

	cin >> T >> N;
	Sum(N);

	return 0;
}

void Sum(string N) {
	int sum = 0;
	for (int i = 0; i < N.length(); i++) {
		sum += ((int)N.at(i) - 48);
	}
	cout << sum;
}