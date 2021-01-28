#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, t = 0;
	int* people;

	cin >> N;
	people = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> people[i];
	}
	sort(people, people + N);

	for (int i = 0; i < N; i++) {
		t += people[i];
		if (i + 1 != N) people[i + 1] += people[i];
	}
	cout << t;

	return 0;
}
