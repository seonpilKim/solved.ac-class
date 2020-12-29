#include <iostream>

using namespace std;

void Find__Max_Min(int*, int);

int main() {
	int N;
	int* array;
	
	cin >> N;

	array = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}

	Find__Max_Min(array, N);

	return 0;
}

void Find__Max_Min(int* array, int N) {
	int max, min;
	max = min = array[0];
	for (int i = 1; i < N; i++) {
		if (array[i] > max) max = array[i];
		else if (array[i] < min) min = array[i];
	}
	cout << min << " " << max;
}