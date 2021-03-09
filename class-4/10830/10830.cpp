#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;
typedef long long ll;

int N;
ll B;

matrix operator* (const matrix&, const matrix&);
matrix Pow(matrix&, ll);
void printRes(const matrix&);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> B;

	matrix input(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
		}
	}

	printRes(Pow(input, B));

	return 0;
}

matrix operator* (const matrix& a, const matrix& b) {
	matrix Res(N, vector<int>(N));

	// move to next row
	for (int i = 0; i < N; i++) {
		// move to next column
		for (int j = 0; j < N; j++) {
			// multipling between two matrix's cells n times, and load their sum to Res[i][j] cell
			for (int k = 0; k < N; k++) {
				Res[i][j] += a[i][k] * b[k][j];
				Res[i][j] %= 1000;
			}
		}
	}
	
	return Res;
}

matrix Pow(matrix& a, ll r) {
	matrix Res(N, vector<int>(N));

	// make Res to a unit matrix
	for (int i = 0; i < N; i++) {
		Res[i][i] = 1;
	}

	while (r > 0) {
		if (r % 2 == 1) 
			Res = a * Res;		
		a = a * a;
		r /= 2;
	}

	return Res;
}

void printRes(const matrix& a) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}