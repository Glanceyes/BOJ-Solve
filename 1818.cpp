#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, ans;

int main() {
    scanf("%d", &n);
    vector<int> v(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        a[i] = INF;
    }

    for (int i = 1; i <= n; i++) {
        vector<int>::iterator low;
        low = lower_bound(a.begin(), a.end(), v[i]);
        int idx = low - a.begin();
        a[idx] = v[i];
        if (ans < idx) ans = idx;
    }

    printf("%d\n", n - ans);

    return 0;
}