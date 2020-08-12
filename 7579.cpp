#include <cstdio>
#include <string.h>
using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int n, m;
int d[100][10001];
int memory[100], cost[100];

int main() {
    scanf("%d %d", &n, &m);
    memset(d, 0, sizeof(d));

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &memory[i]);
    }

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &cost[i]);
        d[i][cost[i]] = memory[i];
    }

    for (int i = 1; i < n; i += 1) {
        for (int j = 0; j <= 10000; j += 1) {
            d[i][j] = d[i - 1][j];
            if (j - cost[i] >= 0) {
                d[i][j] = MAX(d[i][j], d[i - 1][j - cost[i]] + memory[i]);
            }
        }
    }

    int ans = 10000;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j <= 10000; j += 1) {
            if (d[i][j] >= m) {
                if (j < ans) {
                    ans = j;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}