#include <cstdio>
using namespace std;

#define n_max 1000000
#define m_max 1000

int n, m;
int a[n_max + 1];
int s[n_max + 1];
long long v[m_max];

int main() {
    long long result = 0;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i += 1) {
        scanf("%d", &a[i]);
        a[i] %= m;
    }

    for (int i = 1; i <= n; i += 1) {
        s[i] = s[i - 1] + a[i]; s[i] %= m;
        v[s[i]] += 1;
        if (s[i] == 0) {
            result += 1;
        }
    }

    for (int i = 0; i < m; i += 1) {
        result += ((v[i] * (v[i] - 1)) / 2);
    }

    printf("%lld\n", result);

    return 0;
}