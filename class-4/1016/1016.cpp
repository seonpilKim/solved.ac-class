#include <iostream>

using namespace std;

int arr[1000000];

int main() {
	long long min, max, cur, prime, cnt = 0, n = 2;

	cin >> min >> max;
	
	while (n * n <= max) {
		cur = min / (n * n);
		if (cur * n * n != min) cur++;
		while (cur * n * n <= max) {
			arr[cur * n * n - min] = 1;
			cur++;
		}
		n++;
	}

	for (int i = 0; i < max - min + 1; i++) {
		if (arr[i] == 0) cnt++;
	}

	cout << cnt;
	
	return 0;
}
