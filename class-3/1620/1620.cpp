#include <iostream>
#include <map>
#include <cctype>
#include <string>

using namespace std;

int main() {
	map<int, string> poketmons;
	map<string, int> numbers;
	string name;
	int N, M;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> name;
		poketmons.insert(pair<int, string>(i, name));
		numbers.insert(pair<string, int>(name, i));
	}

	for (int i = 0; i < M; i++) {
		cin >> name;
		if (isdigit(name[0])) cout << poketmons.find(stoi(name))->second << "\n";
		else cout << numbers.find(name)->second << "\n";
	}

	return 0;
}