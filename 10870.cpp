#include <cstdio>
using namespace std;

int n, f[21];

int main() {
    scanf("%d", &n);
    f[0] = 0; f[1] = 1;

    for (int i = 2; i <= n; i += 1) {
        f[i] = f[i - 1] + f[i - 2];
    }
    printf("%d\n", f[n]);

    return 0;
}