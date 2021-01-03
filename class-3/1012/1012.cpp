#include <iostream>

using namespace std;

class Cabbage {
public:
    int pos;
    int worm;

    Cabbage() {
        this->pos = 0;
        this->worm = 0;
    }
};

void DFS(Cabbage**, int, int, int, int);

int main() {
    int T, M, N, K, X, Y;
    int cnt;
    Cabbage** field;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        field = new Cabbage * [M];
        for (int j = 0; j < M; j++) {
            field[j] = new Cabbage[N];
        }

        for (int j = 0; j < K; j++) {
            cin >> X >> Y;
            field[X][Y].pos = 1;
        }

        cnt = 0;
        for (int x = 0; x < M; x++) {
            for (int y = 0; y < N; y++) {
                if (field[x][y].pos == 1) {
                    if (field[x][y].worm == 0) {
                        cnt++;
                        DFS(field, x, y, M, N);
                    }
                }
            }
        }
        cout << cnt << "\n";
        for (int k = 0; k < M; k++) {
            delete[] field[k];
        }
        delete[] field;
    }

    return 0;
}

void DFS(Cabbage** field, int x, int y, int M, int N) {
    field[x][y].worm = 1;
    if (x + 1 < M && field[x + 1][y].pos == 1 && field[x + 1][y].worm == 0) DFS(field, x + 1, y, M, N);
    if (y + 1 < N && field[x][y + 1].pos == 1 && field[x][y + 1].worm == 0) DFS(field, x, y + 1, M, N);
    if (x - 1 >= 0 && field[x - 1][y].pos == 1 && field[x - 1][y].worm == 0) DFS(field, x - 1, y, M, N);
    if (y - 1 >= 0 && field[x][y - 1].pos == 1 && field[x][y - 1].worm == 0) DFS(field, x, y - 1, M, N);
}