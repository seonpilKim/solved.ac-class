#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, N, num;
    char i;
    cin >> T;

    while (T--) {
        multiset<int> ms;
        cin >> N;

        while (N--) {
            cin >> i >> num;

            if (i == 'I')  ms.insert(num);           
            else if (i == 'D') {
                if (ms.empty()) continue;

                if (num == 1) ms.erase(--ms.end());             
                else ms.erase(ms.begin());      
            }
        }
        if (ms.empty()) cout << "EMPTY" << '\n';
        else cout << *(--ms.end()) << ' ' << *ms.begin() << "\n";
    }

    return 0;
}
