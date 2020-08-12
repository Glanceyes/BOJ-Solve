#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int n, h[3];
int v[61][61][61];

int bfs() {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(h[0], h[1], h[2]));
    v[h[0]][h[1]][h[2]] = 0;

    while (!q.empty()) {
        queue<tuple<int, int, int>> next_q;
        while (!q.empty()) {
            int t1, t2, t3;
            tie(t1, t2, t3) = q.front(); q.pop();

            if (t1 == 0 && t2 == 0 && t3 == 0) {
                while (!q.empty()) {
                    q.pop();
                }
                return v[t1][t2][t3];
            }

            for (int i = 0; i < 6; i += 1) {
                int n1, n2, n3;
                switch (i) {
                case 0:
                    n1 = (t1 - 9 >= 0) ? (t1 - 9) : 0;
                    n2 = (t2 - 3 >= 0) ? (t2 - 3) : 0;
                    n3 = (t3 - 1 >= 0) ? (t3 - 1) : 0;
                    break;
                case 1:
                    n1 = (t1 - 9 >= 0) ? (t1 - 9) : 0;
                    n2 = (t3 - 3 >= 0) ? (t3 - 3) : 0;
                    n3 = (t2 - 1 >= 0) ? (t2 - 1) : 0;
                    break;
                case 2:
                    n1 = (t2 - 9 >= 0) ? (t2 - 9) : 0;
                    n2 = (t1 - 3 >= 0) ? (t1 - 3) : 0;
                    n3 = (t3 - 1 >= 0) ? (t3 - 1) : 0;
                    break;
                case 3:
                    n1 = (t2 - 9 >= 0) ? (t2 - 9) : 0;
                    n2 = (t3 - 3 >= 0) ? (t3 - 3) : 0;
                    n3 = (t1 - 1 >= 0) ? (t1 - 1) : 0;
                    break;
                case 4:
                    n1 = (t3 - 9 >= 0) ? (t3 - 9) : 0;
                    n2 = (t1 - 3 >= 0) ? (t1 - 3) : 0;
                    n3 = (t2 - 1 >= 0) ? (t2 - 1) : 0;
                    break;
                case 5:
                    n1 = (t3 - 9 >= 0) ? (t3 - 9) : 0;
                    n2 = (t2 - 3 >= 0) ? (t2 - 3) : 0;
                    n3 = (t1 - 1 >= 0) ? (t1 - 1) : 0;
                    break;
                }

                if (v[n1][n2][n3] == -1 ||
                    v[n1][n2][n3] > v[t1][t2][t3] + 1) {
                    v[n1][n2][n3] = v[t1][t2][t3] + 1;
                    next_q.push(tie(n1, n2, n3));
                }
            }
        }
        q = next_q;
    }

    return 0;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &h[i]);
    }

    for (int i = 0; i <= 60; i += 1) {
        for (int j = 0; j <= 60; j += 1) {
            for (int k = 0; k <= 60; k += 1) {
                v[i][j][k] = -1;
            }
        }
    }

    printf("%d\n", bfs());

    return 0;
}