#include <cstdio>
using namespace std;

#define N_MAX 100

int n, l;
int map[N_MAX + 2][N_MAX + 2];
int canRow[N_MAX + 2][N_MAX + 2];
int canCol[N_MAX + 2][N_MAX + 2];
bool goRow[N_MAX + 2], goCol[N_MAX + 2];

int main() {
    int result = 0;
    scanf("%d %d", &n, &l);

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 1; i <= n; i += 1) {
        map[0][i] = map[1][i];
        map[n + 1][i] = map[n][i];
    }
    for (int i = 1; i <= n; i += 1) {
        map[i][0] = map[i][1];
        map[i][n + 1] = map[i][n];
    }

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n - l + 1; j += 1) {
            bool flag = true;
            for (int k = j; k < j + l; k += 1) {
                if (map[i][j] != map[i][k] || canRow[i][k]) {
                    flag = false; break;
                }
            }
            if (flag) {
                if (map[i][j - 1] - 1 == map[i][j]) {
                    for (int k = j; k < j + l; k += 1) {
                        canRow[i][k] = -1;
                    }
                }
                else if (map[i][j + l] == map[i][j + l - 1] + 1) {
                    for (int k = j; k < j + l; k += 1) {
                        canRow[i][k] = 1;
                    }
                }
            }
        }
        goRow[i] = true;
        for (int j = 1; j < n; j += 1) {
            if (map[i][j] != map[i][j + 1]) {
                if (canRow[i][j + 1] == -1 &&
                    map[i][j] + canRow[i][j + 1] == map[i][j + 1]) {
                    continue;
                }
                else if (canRow[i][j] == 1 &&
                    map[i][j] + canRow[i][j] == map[i][j + 1]) {
                    continue;
                }
                goRow[i] = false; break;
            }
        }
    }

    for (int j = 1; j <= n; j += 1) {
        for (int i = 1; i <= n - l + 1; i += 1) {
            bool flag = true;
            for (int k = i; k < i + l; k += 1) {
                if (map[i][j] != map[k][j] || canCol[k][j]) {
                    flag = false; break;
                }
            }
            if (flag) {
                if (map[i - 1][j] - 1 == map[i][j]) {
                    for (int k = i; k < i + l; k += 1) {
                        canCol[k][j] = -1;
                    }
                }
                else if (map[i + l][j] == map[i + l - 1][j] + 1) {
                    for (int k = i; k < i + l; k += 1) {
                        canCol[k][j] = 1;
                    }
                }
            }
        }
        goCol[j] = true;
        for (int i = 1; i < n; i += 1) {
            if (map[i][j] != map[i + 1][j]) {
                if (canCol[i + 1][j] == -1 && 
                    map[i][j] + canCol[i + 1][j] == map[i + 1][j]) {
                    continue;
                }
                else if (canCol[i][j] == 1 &&
                    map[i][j] + canCol[i][j] == map[i + 1][j]){
                    continue;
                }
                goCol[j] = false; break;
            }
        }
    }
    /*
    printf("\n");
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            (canRow[i][j] >= 0) ? (printf("+%d ", canRow[i][j])) : (printf("%d ", canRow[i][j]));
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            (canCol[i][j] >= 0) ? (printf("+%d ", canCol[i][j])) : (printf("%d ", canCol[i][j]));
        }
        printf("\n");
    }
    printf("\n");
    */
    for (int i = 1; i <= n; i += 1) {
        if (goRow[i]) { result += 1; }
        //printf("%d번째 행: %d\n", i, goRow[i]);
    }
    //printf("\n");
    for (int i = 1; i <= n; i += 1) {
        if (goCol[i]) { result += 1; }
        //printf("%d번째 열: %d\n", i, goCol[i]);
    }
    printf("%d\n", result);

    return 0;
}