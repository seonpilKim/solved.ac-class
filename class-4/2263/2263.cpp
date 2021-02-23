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

    /*
        Indexing the inorder traversal
    */
    for (int i = 0; i < N; i++)
        idx[inOrder[i]] = i;
}

void preOrder(int inBegin, int inEnd, int postBegin, int postEnd) {
    /*
        Recursive call termination condition
    */
    if (inBegin > inEnd || postBegin > postEnd)
        return;

    /*
        Printing the root of the current subtree
    */
    int root = postOrder[postEnd];
    cout << root << " ";

    int new__inBegin;
    int new__inEnd;
    int new__postBegin;
    int new__postEnd;
    int size__left_subtree = idx[root] - inBegin;
    
    // left subtree
    new__inEnd = idx[root] - 1;
    new__postEnd = postBegin + size__left_subtree - 1;
    preOrder(inBegin, new__inEnd, postBegin, new__postEnd);

    // right subtree
    new__inBegin = idx[root] + 1;
    new__postBegin = postBegin + size__left_subtree;
    new__postEnd = postEnd - 1;
    preOrder(new__inBegin, inEnd, new__postBegin, new__postEnd);
}