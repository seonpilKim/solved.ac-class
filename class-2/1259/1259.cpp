#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string cmd, revcmd;

	while (true) {
		cin >> cmd;
		if (cmd == "0") break;
		revcmd = cmd;
		reverse(cmd.begin(), cmd.end());
		if (cmd == revcmd) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}