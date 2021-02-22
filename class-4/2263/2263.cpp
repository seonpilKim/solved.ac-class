#include <iostream>

using namespace std;

#define MAX 1000001

int N;
int inOrder[MAX], postOrder[MAX];
int idx[MAX];

void input();
void preOrder(int, int, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    preOrder(0, N - 1, 0, N - 1);

    return 0;
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> inOrder[i];

    for (int i = 0; i < N; i++)
        cin >> postOrder[i];

    for (int i = 0; i < N; i++)
        idx[inOrder[i]] = i;
}

void preOrder(int inBegin, int inEnd, int postBegin, int postEnd) {
    if (inBegin > inEnd || postBegin > postEnd)
        return;

    int root = postOrder[postEnd];
    cout << root << " ";

    // left subtree
    preOrder(inBegin, idx[root] - 1, postBegin, postBegin + (idx[root] - inBegin) - 1);

    // right subtree
    preOrder(idx[root] + 1, inEnd, postBegin + (idx[root] - inBegin), postEnd - 1);
}