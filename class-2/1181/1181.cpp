#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool MySort(string, string);

int main() {
	int N;
	string str;
	vector<string> Svector;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		Svector.push_back(str);
	}

	stable_sort(Svector.begin(), Svector.end());

	Svector.erase(unique(Svector.begin(), Svector.end()), Svector.end());

	stable_sort(Svector.begin(), Svector.end(), MySort);

	for (const auto& v : Svector) {
		cout << v << "\n";
	}

	return 0;
}

bool MySort(string A, string B) {
	return A.size() < B.size();
}