#include <iostream>

using namespace std;

void Scale(int*);

int main() {
	int scale[8];
	for (int i = 0; i < 8; i++) {
		cin >> scale[i];
	}

	Scale(scale);

	return 0;
}

void Scale(int* scale) {
	bool ascending = false, descending = false, mixed = false;
	for (int i = 1; i < 7; i++) {
		if (scale[i - 1] < scale[i] && scale[i] < scale[i + 1]) ascending = true;		
		else if (scale[i - 1] > scale[i] && scale[i] > scale[i + 1]) descending = true;
		else {
			cout << "mixed";
			return;
		}
	}
	if (ascending) cout << "ascending";
	else if (descending) cout << "descending";
}
