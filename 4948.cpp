#include <cstdio>
#include <string.h>
using namespace std;

int n;
bool p[250000];

int main() {
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        memset(p, false, sizeof(p));

        p[0] = p[1] = true;

        for (int i = 2; i * i <= n * 2; i += 1) {
            for (int j = i * 2; j <= n * 2; j += i) {
                p[j] = true;
            }
        }

        int cnt = 0;

        for (int i = n + 1; i <= n * 2; i += 1) {
            if (!p[i]) {
                cnt += 1;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}