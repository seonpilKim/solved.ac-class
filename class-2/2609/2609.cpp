#include <iostream>

using namespace std;

int main() {
	int A, B, M;
	int r = 1;

	cin >> A >> B;
	
	M = A * B;

	while (true) {
		r = A % B;
		if (r == 0) break;
		A = B;
		B = r;
	}

	cout << B << "\n" << M / B;
	return 0;
}