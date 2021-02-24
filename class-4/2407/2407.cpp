#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 101

string dp[MAX][MAX];

string Combination(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;

	cout << Combination(N, M);

	return 0;
}

string BigInteger(string comb1, string comb2) {
	int sum = 0;
	string result = "";

    while (!comb1.empty() || !comb2.empty() || sum) {
        if (!comb1.empty()) {
            sum += comb1.back() - '0';
            comb1.pop_back();
        }

        if (!comb2.empty()){
            sum += comb2.back() - '0';
            comb2.pop_back();
        }

        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    
    //  #include <algorithm>
    reverse(result.begin(), result.end());

    return result;
}

string Combination(int n, int r) {
    // nCr = nCo = 1
	if (n == r || r == 0) return "1";


    //  Memoization
    string& result = dp[n][r];
    if (result != "") return result;
    else result = BigInteger(Combination(n - 1, r - 1), Combination(n - 1, r));

    return result;
}