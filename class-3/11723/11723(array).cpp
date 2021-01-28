#include <iostream>

using namespace std;

int main() {
	int set[21] = { 0 };
	int N, x;
	string cmd;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	while (N--) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> x;
			set[x] = 1;
		}
		else if (cmd == "remove") {
			cin >> x;
			set[x] = 0;
		}
		else if (cmd == "check") {
			cin >> x;
			if (set[x] == 1) cout << "1\n";
			else cout << "0\n";
		}
		else if (cmd == "toggle") {
			cin >> x;
			if (set[x] == 1) set[x] = 0;
			else set[x] = 1;
		}
		else if (cmd == "all") {
			for (int i = 1; i < 21; i++) {
				set[i] = 1;
			}
		}
		else if (cmd == "empty") {
			for (int i = 1; i < 21; i++) {
				set[i] = 0;
			}
		}
	}

	return 0;
}
