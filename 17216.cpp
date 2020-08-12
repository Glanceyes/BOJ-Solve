#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define N_MAX 1000

int a[N_MAX];
int d[N_MAX];
int p[N_MAX];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); d[i] = a[i];
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] < a[j]) {
                if (d[i] < d[j] + a[i]) {
                    d[i] = d[j] + a[i];
                }
            }
            if (ans < d[i]) ans = d[i];
        }
    }
    printf("%d\n", ans);

    return 0;
}