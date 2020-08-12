#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define N_MAX 10001
#define INF 987654321

int n;
int d[N_MAX];

int ab(int x) {
    if (x < 0) return -x;
    return x;
}

int main() {
    scanf("%d", &n);
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        int bx, by; scanf("%d %d", &bx, &by);
        b[i] = { bx, by };
    }
    sort(b.begin(), b.end());
    fill(d, d + N_MAX, INF);
    d[0] = 0;

    for (int i = 1; i <= n; i++) {
        int mx = ab(b[i - 1].second) * 2;
        for (int j = i; j > 0; j--) {
            mx = max(mx, max(ab(b[i - 1].first - b[j - 1].first), ab(b[j - 1].second * 2)));
            d[i] = min(d[i], d[j - 1] + mx);
        }
    }
    printf("%d\n", d[n]);

    return 0;
}