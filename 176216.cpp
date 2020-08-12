#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n), d(n + 1), p(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        d[i] = INF;
    }
    d[n] = INF;
    reverse(a.begin(), a.end());
    int l = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        auto low = lower_bound(d.begin(), d.end(), a[i]);
        int idx = low - d.begin();
        d[idx] = a[i];
        if (!p[idx].empty()) {
            p[idx].pop_back();
        }
        p[idx].push_back(a[i]);
        if (l < idx) l = idx;
    }
    for (auto x : p[l]) {
        ans += x;
    }
    printf("%d\n", x);

    return 0;
}