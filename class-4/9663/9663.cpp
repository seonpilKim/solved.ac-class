#include <iostream>
#include <math.h>

#define MAX 16

using namespace std;

int N;
int cnt;
int col[MAX];

void N_Queen(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	N_Queen(1);

	cout << cnt;

	return 0;
}

void N_Queen(int row) {
	if (row == N + 1) {
		cnt++;
		return;
	}
	
	/*
		It is examined in order from row 1 to row N, 
		so it is not necessary to confirm that queens exist in the same row.
	*/
	for (int c = 1; c <= N; c++) {
		bool place = true;
		/*
			placing the queen in a condition-fitting position 
			while exploring the entire column from row 1 to the current row.
		*/
		for (int r = 1; r < row; r++) {
			if (col[r] == c || abs(col[r] - c) == abs(r - row)) {
				place = false;
				break;
			}
		}
		if (place) {
			col[row] = c;
			N_Queen(row + 1);
		}
	}
}