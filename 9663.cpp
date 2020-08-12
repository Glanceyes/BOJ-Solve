#include <cstdio>
#include <string.h>

using namespace std;

#define MAX 15

int n, counter;
int dirx[3] = { 1, 1, 1 };
int diry[3] = { 1, 0, -1 };
int check[MAX][MAX];

void dfsPaint(int x, int y, int dx, int dy, int paint) {
    if (x + dx >= 0 && x + dx < n &&
        y + dy >= 0 && y + dy < n) {
        if (check[x + dx][y + dy] == -1) {
            check[x + dx][y + dy] = paint;
        }
        dfsPaint(x + dx, y + dy, dx, dy, paint);
    }
    return;
}

void dfsErase(int x, int y, int dx, int dy, int erase) {
    if (x + dx >= 0 && x + dx < n &&
        y + dy >= 0 && y + dy < n) {
        if (check[x + dx][y + dy] == erase) {
            check[x + dx][y + dy] = -1;
        }
        dfsErase(x + dx, y + dy, dx, dy, erase);
    }
    return;
}

void go(int row) {
    for (int i = 0; i < n; i += 1) {
        if (check[row][i] == -1) {
            if (row == n - 1) {
                counter += 1; continue;
            }
            check[row][i] = row;
            for (int j = 0; j < 3; j += 1) {
                dfsPaint(row, i, dirx[j], diry[j], row);
            }
            go(row + 1);
            for (int j = 0; j < 3; j += 1) {
                dfsErase(row, i, dirx[j], diry[j], row);
            }
            check[row][i] = -1;
        }
    }
}

int main() {
    scanf("%d", &n);
    memset(check, -1, sizeof(check));

    go(0);
    printf("%d\n", counter);

    return 0;
}