#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int main() {
    int t; scanf("%d", &t);
    for (int cnt = 1; cnt <= t; cnt++) {
        int n; scanf("%d", &n);
        int ans = 0;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
        }

        for (int start = 1; start <= n; start++) {
            vector<int> a(n + 2 - start, INF); a[0] = 0;
            int max_idx = 1;
            for (int i = start; i <= n; i++) {
                vector<int>::iterator low;
                low = lower_bound(a.begin(), a.end(), v[i]);
                int idx = low - a.begin();
                a[idx] = v[i];
                if (max_idx < idx) {
                    max_idx = idx;
                }
                ans += max_idx;
            }
        }

        printf("Case #%d: %d\n", cnt, ans);
    }

    return 0;
}