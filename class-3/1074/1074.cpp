#include <iostream>
#include <cmath>

using namespace std;

int N, row, col;
int result;

void Z(int x, int y, int len) {
    if (x == row && y == col) {
        cout << result;
        exit(0);
    }

    if (len == 1) {
        result++; 
        return;
    }

    if (!(x <= row && row < x + len && y <= col && col < y + len)) {
        result += len * len;
        return;
    }

    Z(x, y, len / 2);
    Z(x, y + len / 2, len / 2);
    Z(x + len / 2, y, len / 2);
    Z(x + len / 2, y + len / 2, len / 2);
}

int main() {
    cin >> N >> row >> col;

    Z(0, 0, pow(2, N));

    return 0;
}
