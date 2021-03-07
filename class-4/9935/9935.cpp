#include <iostream>
#include <vector>

using namespace std;

int main() {
	string str;
	string boomb;
	vector<char> ans;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str >> boomb;

	int size = str.size();

	for (int i = 0; i < str.size(); i++) {
		ans.push_back(str[i]);

		if (str[i] == boomb[boomb.size() - 1]) {
			bool isboomb = true;

			for (int j = 0; j < boomb.size(); j++) {
				if (ans[ans.size() - 1 - j] != boomb[boomb.size() - 1 - j]) {
					isboomb = false;
					break;
				}
			}

			if (isboomb) {
				for (int j = 0; j < boomb.size(); j++) {
					ans.pop_back();
				}
				size -= boomb.size();
			}
		}
	}

	if (size) {
		for (int i = 0; i < size; i++) {
			cout << ans[i];
		}
	}
	else cout << "FRULA";

	return 0;
}
