#include <iostream>

using namespace std;

string Is__matchPS(string);

int main() {
	int T;
	string PS;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> PS;
		cout << Is__matchPS(PS) << "\n";
	}

	return 0;
}

string Is__matchPS(string PS) {
	int cnt = 0;

	for (int i = 0; i < PS.length(); i++) {
		if (PS.at(i) == '(') {
			cnt++;
		}
		else if(PS.at(i) == ')') {
			if (cnt == 0) return "NO";
			cnt--;
		}
	}
	if (cnt != 0) return "NO";
	return "YES";
}
