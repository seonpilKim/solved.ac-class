#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 125251
#define MAX_HEIGHT 501

int tree[MAX_SIZE];
int start[MAX_HEIGHT];
int height, idx = 1;

void input();
void search(int);

int main() {
	input();

	search(1);

	return 0;
}

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> height;

	start[1] = 1;
	for (int i = 1; i <= height; i++) {
		for (int j = 0; j < i; j++) {
			cin >> tree[idx++];
		}
		start[i + 1] = idx;
	}
}

void search(int h) {
	if (h < height) search(h + 1);	
	if (h == 1) {
		cout << tree[1];
		return;
	}

	int par_idx = start[h - 1];
	int cur_idx = start[h];

	while (par_idx < start[h]) {
		tree[par_idx++] += max(tree[cur_idx], tree[cur_idx + 1]);
		cur_idx++;
	}
}