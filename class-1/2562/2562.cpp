#include <iostream>

using namespace std;

void Find__Max(int*);

int main() {
	int num[9];

	for (int i = 0; i < 9; i++) {
		cin >> num[i];
	}

	Find__Max(num);

	return 0;
}

void Find__Max(int* num) {
	int max = num[0], idx = 0;
	for (int i = 1; i < 9; i++) {
		if (max < num[i]) {
			max = num[i];
			idx = i;
		}
	}
	cout << max << "\n" << (idx + 1);
}

