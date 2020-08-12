#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int s[201];
int d[201];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }


    for (int i = 1; i <= n; i++) {
        d[i] = 1;
        for (int j = 1; j < i; j++) {
            if (s[i] >= s[j]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }

    printf("%d\n", n - ans);

    return 0;
}