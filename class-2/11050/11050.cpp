#include <iostream>

using namespace std;

int Binomial_Coefficient(int, int);

int main() {
	int N, K;

	cin >> N >> K;

	cout << Binomial_Coefficient(N, K);

	return 0;
}

int Binomial_Coefficient(int N, int K) {
	if (K < 0 || K > N) return 0;
	else if (N == K || K == 0) return 1;
	return Binomial_Coefficient(N - 1, K - 1) + Binomial_Coefficient(N - 1, K);
}