#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int stiker[2][MAX];
int n;
int Max;

void findMax(int, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;

	cin >> T;

	while (T--) {
		cin >> n;

		for (int r = 0; r < 2; r++) {
			for (int c = 0; c < n; c++) {
				cin >> stiker[r][c];
			}
		}
		Max = 0;
		findMax(0, 0, 0);
		findMax(1, 0, 0);
		cout << Max << '\n';
	}

	return 0;
}

void findMax(int r, int c, int v) {
	int value = v + stiker[r][c];
	Max = max(value, Max);
	
	switch (r) {
	case 0 :
		if (c + 1 < n) findMax(r + 1, c + 1, value);
		if (c + 2 < n) findMax(r + 1, c + 2, value);
		break;
	case 1 :
		if (c + 1 < n) findMax(r - 1, c + 1, value);
		if (c + 2 < n) findMax(r - 1, c + 2, value);
		break;
	}
}