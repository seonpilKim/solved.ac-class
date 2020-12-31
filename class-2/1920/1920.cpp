#include <iostream>
#include <map>

using namespace std;

int main() {
	int N, M, input;
	int* X;
	map<int, int> map;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		map.insert(pair<int, int>(input, input));
	}

	cin >> M;
	X = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> X[i];
	}

	for (int i = 0; i < M; i++) {
		if (map.find(X[i]) == map.end()) {
			cout << "0\n";
		}
		else {
			cout << "1\n";
		}
	}

	return 0;
}