#include <iostream>
#include <algorithm>

using namespace std;

int arr[500002];

int main()
{
	int N, M, card, n;
	int* lower, * upper;

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	
	scanf_s("%d", &M);
	sort(arr, arr + N);

	for (int i = 0; i < M; i++)
	{
		scanf_s("%d", &card);

		lower = lower_bound(arr, arr + N, card);
		upper = upper_bound(arr, arr + N, card);
		n = upper - lower;

		printf("%d ", n);
	}

	return 0;
}