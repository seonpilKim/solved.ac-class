#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, K;
	queue<int> people;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		people.push(i);
	}

	while (true) {
		if (people.size() == N) {
			cout << "<";
			for (int i = 1; i < K; i++) {
				people.push(people.front());
				people.pop();
			}
			cout << people.front();
			people.pop();
		}

		if (people.size() == 0) {
			cout << ">";
			break;
		}

		for (int i = 1; i < K; i++) {
			people.push(people.front());
			people.pop();
		}
		cout << ", " << people.front();
		people.pop();	
	}

	return 0;
}