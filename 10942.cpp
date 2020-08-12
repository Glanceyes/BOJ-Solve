#include <cstdio>

using namespace std;

#define MAX 2000

int n, m;
int num[MAX + 1];
int pdr[MAX + 1][MAX + 1];

// Àç±Í·Î
int find(int x, int y) {
    if (x == y) {
        return (pdr[x][y] = 1);
    }
    if (pdr[x][y] >= 0) {
        return pdr[x][y];
    }
    if (x + 1 == y) {
        if (num[x] == num[y]) {
            return (pdr[x][y] = 1);
        }
        else {
            return (pdr[x][y] = 0);
        }
    }
    if (num[x] != num[y]) {
        return (pdr[x][y] = 0);
    }
    else {
        return (pdr[x][y] = find(x + 1, y - 1));
    }
}

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i += 1) {
        scanf("%d", &num[i]);
        /*
        for (int j = 1; j <= n; j += 1) {
            pdr[i][j] = -1;
        }
        */
    }

    /* Àç±Í·Î
    for (int i = 1; i <= n; i += 1) {
        for (int j = n; j >= i; j -= 1) {
            find(i, j);
        }
    }
    */

    for (int i = 1; i <= n; i += 1) {
        pdr[i][i] = 1;
    }
    for (int i = 1; i <= n - 1; i += 1) {
        if (num[i] == num[i + 1]) {
            pdr[i][i + 1] = 1;
        }
    }
    for (int i = 3; i <= n; i += 1) {
        for (int j = 1; j <= n - i + 1; j += 1) {
            int k = j + i - 1;
            if (num[j] == num[k]) {
                pdr[j][k] = pdr[j + 1][k - 1];
            }
            else {
                pdr[j][k] = 0;
            }
        }
    }


    scanf("%d", &m);
    while (m--) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", pdr[s][e]);
    }

    return 0;
}