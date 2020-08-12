#include <cstdio>
using namespace std;

int n, ans = -1;

int main() {
    scanf("%d", &n);

    for (int i = 0; i <= n / 5; i += 1) {
        for (int j = 0; j <= n / 3; j += 1) {
            if (i * 5 + j * 3 == n) {
                ans = i + j;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}