#include <iostream>
#include <map>

using namespace std;

class Person {
public:
	map<int, int> cards;

	Person(){}

	void Add(int X) {
		if (cards.find(X) == cards.end()) cards.insert(pair<int, int>(X, 1));		
		else cards.find(X)->second++;		
	}

	int Search(int X) {
		if (cards.find(X) == cards.end()) return 0;
		else return cards.find(X)->second;
	}
};

int main() {
	int N, M, card;
	Person sang_geun;
	
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &card);
		sang_geun.Add(card);
	}

	scanf_s("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &card);
		printf("%d ", sang_geun.Search(card));
	}

	return 0;
}