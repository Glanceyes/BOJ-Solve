#include <cstdio>
using namespace std;

int n, m, k, cnt;

int main() {
    scanf("%d %d %d", &n, &m, &k);

    while (cnt < k) {
        if (n <= m * 2) {
            m -= 1;
        }
        else {
            n -= 1;
        }
        cnt += 1;
    }

    if (n <= m * 2) {
        printf("%d\n", n / 2);
    }
    else {
        printf("%d\n", m);
    }

    return 0;
}