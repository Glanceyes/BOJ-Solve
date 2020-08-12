#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define v_max 1000000

int n, cnt;
vector<int> result, s;

int main() {
    scanf("%d", &n);

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &a[i].first);
        a[i].second = 0;
    }

    s.push_back(a[0].first);
    cnt += 1; a[0].second = cnt;

    for (int i = 1; i < n; i += 1) {
        if (a[i].first > s.back()) {
            s.push_back(a[i].first);
            cnt += 1; a[i].second = cnt;
        }
        else {
            auto iter = lower_bound(s.begin(), s.end(), a[i].first);
            *iter = a[i].first;
            a[i].second = iter - s.begin() + 1;
        }
    }
    printf("%d\n", cnt);

    for (int i = n - 1; i >= 0 && cnt > 0; i -= 1) {
        if (a[i].second == cnt) {
            result.push_back(a[i].first); cnt -= 1;
        }
    }

    reverse(result.begin(), result.end());
    for (int i = 0; i < (int)result.size(); i += 1) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}