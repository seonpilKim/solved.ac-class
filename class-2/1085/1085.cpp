#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x, y, w, h;
	int array[4];

	cin >> x >> y >> w >> h;
	array[0] = x;
	array[1] = y;
	array[2] = w - x;
	array[3] = h - y;

	sort(array, array + 4);
	cout << array[0];

	return 0;
}