#include <iostream>

using namespace std;

int main() {
	long long A, B, C;
	long long r = 1;

	cin >> A >> B >> C;

	while (B != 0) {
		if (B & 1) r = (r * A) % C;	// B°¡ È¦¼öÀÎ °æ¿ì
		A = (A * A) % C;
		B >>= 1;					// B¸¦ 2·Î ³ª´®
	}

	cout << r;

	return 0;
}