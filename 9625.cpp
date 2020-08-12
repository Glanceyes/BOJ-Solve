#include <cstdio>
using namespace std;

#define K_MAX 46

int d[K_MAX][2];

int main() {
    int k; scanf("%d", &k);
    d[0][0] = 1; d[0][1] = 0;
    for (int i = 1; i <= k; i++) {
        d[i][0] = d[i - 1][1];
        d[i][1] = d[i - 1][0] + d[i - 1][1];
    }

    printf("%d %d\n", d[k][0], d[k][1]);

    return 0;
}