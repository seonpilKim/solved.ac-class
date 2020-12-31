#include <iostream>

using namespace std;

int main() {
	int T, H, W, N;
	int cnt;
	int h, w;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cnt = 0;
		h = 0;
		w = 1;

		cin >> H >> W >> N;
		
		while (cnt < N) {
			h++;
			if (h == H && cnt + 1 != N) {
				h = 0;
				w++;
			}
			cnt++;
		}

		cout << (h * 100) + w << "\n";
	}

	return 0;
}