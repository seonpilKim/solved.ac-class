#include <iostream>

using namespace std;

int main() {
	int bit = 0;
	int N, x;
	string cmd;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			cin >> x;
			bit |= (1 << --x);
		}
		else if (cmd == "remove") {
			cin >> x;
			bit &= ~(1 << --x);
		}
		else if (cmd == "check") {
			cin >> x;
			if ((bit & (1 << --x)) == (1 << x)) cout << "1\n";
			else cout << "0\n";
		}
		else if (cmd == "toggle") {
			cin >> x;
			if ((bit & (1 << --x)) == (1 << x)) bit &= ~(1 << x);
			else bit |= (1 << x);
		}
		else if (cmd == "all") {
			bit = 0xFFFFF;
		}
		else if (cmd == "empty") {
			bit = 0;
		}
	}
	
	return 0;
}
