#include <iostream>
#include <algorithm>

using namespace std;

class coordinate {
public:
	int data;
	int idx;
	coordinate() {}
};

bool compare(coordinate, coordinate);

int main() {
	int N, data, last, press = 0;
	int* rm;
	coordinate* pm;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	pm = new coordinate[N];
	rm = new int[N];
	
	for (int i = 0; i < N; i++) {
		cin >> data;
		pm[i].data = data;
		pm[i].idx = i;
	}

	sort(pm, pm + N, compare);
	
	last = pm[0].data;
	rm[pm[0].idx] = press;

	for (int i = 1; i < N; i++) {
		if (last == pm[i].data) rm[pm[i].idx] = press;
		else {
			rm[pm[i].idx] = ++press;
			last = pm[i].data;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << rm[i] << " ";
	}

	return 0;
}

bool compare(coordinate a, coordinate b) {
	return a.data < b.data;
}