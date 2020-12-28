#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double A, B;

	cin >> A >> B;

	cout.precision(9);
	cout << fixed << A / B;

	return 0;
}