#include <iostream>

using namespace std;

void Rep(int, string);

int main() {
	int T, R;
	string S;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> R >> S;
		Rep(R, S);
	}
	return 0;
}

void Rep(int R, string S) {
	for (int i = 0; i < S.length(); i++) {
		for (int j = 0; j < R; j++) {
			cout << S.at(i);
		}
	}
	cout << "\n";
}
