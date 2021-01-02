#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	int N, M, card;
	unordered_map<int, int> map;

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &card);

		map[card]++;
	}
	
	scanf_s("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf_s("%d", &card);

		printf("%d ", map[card]);
	}

	return 0;
}