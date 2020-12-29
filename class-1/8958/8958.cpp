#include <iostream>

using namespace std;

void Score(string);

int main() {
	int T;
	string S;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> S;
		Score(S);
	}

	return 0;
}

void Score(string S) {
	int score = 0, tmp = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S.at(i) == 'O') {
			tmp++;
			score += tmp;
		}
		else tmp = 0;
	}
	cout << score << "\n";
}