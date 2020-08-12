#include <cstdio>
#include <limits.h>
using namespace std;

#define MAX 500

int t, k;
int s[MAX];
int n[MAX];
int d[MAX][MAX];

int main() {
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &k);
        for (int i = 0; i < k; i += 1) {
            scanf("%d", &n[i]);
        }

        for (int i = 0; i < k; i += 1) {
            if (i == 0) {
                s[i] = n[i];
            }
            else {
                s[i] = s[i - 1] + n[i];
            }
        }

        for (int i = 2; i <= k; i += 1) {
            for (int j = 0; j + i - 1 < k; j += 1) {
                int l = j + i - 1;
                if (l < k) {
                    d[j][l] = INT_MAX;
                    for (int m = j; m < l; m += 1) {
                        int tmp = s[l];
                        if (j > 0) {
                            tmp -= s[j - 1];
                        }
                        if (d[j][l] > d[j][m] + d[m + 1][l] + tmp) {
                            d[j][l] = d[j][m] + d[m + 1][l] + tmp;
                        }
                    }
                }
            }
        }
        printf("%d\n", d[0][k - 1]);
    }

    return 0;
}