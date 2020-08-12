#include <cstdio>
using namespace std;

int m, n, mn, sum;
bool p[10001];

int main() {
    scanf("%d %d", &m, &n);

    p[0] = p[1] = true;

    for (int i = 2; i * i <= n; i += 1) {
        for (int j = i * 2; j <= n; j += i) {
            p[j] = true;
        }
    }

    for (int i = m; i <= n; i += 1) {
        if (!p[i]) {
            if (mn == 0) {
                mn = i;
            }
            sum += i;
        }
    }
    if (sum) {
        printf("%d\n%d\n", sum, mn);
    }
    else {
        printf("-1\n");
    }
    return 0;
}