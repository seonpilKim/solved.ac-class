#include <iostream>

using namespace std;

int cnt0 = 1, cnt1 = 0;

int main() {
    int T, N, tmp;
    
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            tmp = cnt0;
            cnt0 = cnt1;
            cnt1 += tmp;
        }
        cout << cnt0 << " " << cnt1 << "\n";
        cnt0 = 1;
        cnt1 = 0;
    }
    return 0;
}
