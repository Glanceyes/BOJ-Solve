#include <cstdio>
#include <algorithm>
using namespace std;

const int T_MAX = 200;
const int A_MAX = 4000;
const int MOD = 1000000;
int t, a, s, b;
int num[T_MAX + 1];
int dp[A_MAX + 1][T_MAX + 1];

int go(int x, int y) {
    if (x < 0 || y < 0) return 0;
         
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i <= num[y]; i++) {
        ret += go(x - i, y - 1);
        ret %= MOD;
    }
    return ret;
}

int main() {
    scanf("%d %d %d %d", &t, &a, &s, &b);
    for (int i = 0; i < a; i++) {
        int x; scanf("%d", &x);
        num[x] += 1;
    }
    for (int i = 0; i <= A_MAX; i++) {
        for (int j = 0; j <= T_MAX; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i <= t; i++) {
        dp[0][i] = 1;
    }

    int ans = 0;
    for (int i = s; i <= b; i++) {
        ans += go(i, t); ans %= MOD;
    }

    printf("%d\n", ans % MOD);

    return 0;
}