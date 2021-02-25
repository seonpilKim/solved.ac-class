#include <iostream>
#include <stack>

#define Left 1
#define Right 2

using namespace std;

int N;
char** star;
void Star();
void Print();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	star = new char* [N + 1];
	for (int i = 0; i <= N; i++) {
		star[i] = new char[2 * N];
		fill(star[i], star[i] + 2 * N, ' ');
	}

	Star();
	Print();

	return 0;
}

void Print() {
	for (int h = 1; h <= N; h++) {
		for (int idx = 1; idx < 2 * N; idx++) {
			cout << star[h][idx];
		}
		cout << '\n';
	}
}

void Star() {
	stack<pair<int, int>> tempS;
	stack<pair<int, int>> S;
	tempS.push(make_pair(1, N));

	while (!tempS.empty()) {
		while (!tempS.empty()) {
			S.push(tempS.top()); tempS.pop();
		}

		while (!S.empty()) {
			int h = S.top().first;
			int s = S.top().second;
			S.pop();

			star[h][s] = '*'; h++;
			star[h][s - 1] = star[h][s + 1] = '*'; h++;
			star[h][s - 2] = star[h][s - 1] = star[h][s] = star[h][s + 1] = star[h][s + 2] = '*'; h++;

			if (h < N) {
				if (!tempS.empty()) {
					int top = 0;

					if (tempS.top() == make_pair(h, s - 3)) top = Left;
					else if (tempS.top() == make_pair(h, s + 3)) top = Right;

					if (top == Left) {
						tempS.pop();
						tempS.push(make_pair(h, s + 3));
					}
					else if (top == Right) {
						tempS.pop();
						tempS.push(make_pair(h, s - 3));
					}
					else {
						tempS.push(make_pair(h, s - 3));
						tempS.push(make_pair(h, s + 3));
					}
				}
				else if (tempS.empty()) {
					tempS.push(make_pair(h, s - 3));
					tempS.push(make_pair(h, s + 3));
				}
			}
		}
	}
}