#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
string boomb;

int main() {
	stack<int> s;

	cin >> str >> boomb;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == boomb[0]) s.push(i);
	}

	while (!s.empty()) {
		int idx = s.top(); s.pop();
		int cnt = 0;
		for (int i = 0; i < boomb.size(); i++) {
			if (str[idx + i] == boomb[i]) cnt++;
		}
		if (cnt == boomb.size()) {
			string tmp = str.substr(0, idx);
			string tmp1 = str.substr(idx + boomb.size());
			str = tmp + tmp1;
		}
	}

	if (str.size()) cout << str;
	else cout << "FRULA";

	return 0;
}
