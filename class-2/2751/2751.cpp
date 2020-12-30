#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T, N;
	int* Narray;

	cin >> T;
	Narray = new int[T];

	for (int i = 0; i < T; i++) {
		cin >> N;
		Narray[i] = N;
	}

	sort(Narray, Narray + T);

	for (int i = 0; i < T; i++) {
		cout << Narray[i] << "\n";
	}

	return 0;
}
