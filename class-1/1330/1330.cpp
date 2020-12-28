#include <iostream>

using namespace std;

void Compare(int, int);

int main() {
	int A, B;

	cin >> A >> B;

	Compare(A, B);

	return 0;
}

void Compare(int A, int B) {
	if (A > B) cout << ">";
	else if (A < B) cout << "<";
	else cout << "==";
}