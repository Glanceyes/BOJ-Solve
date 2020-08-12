#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define N_MAX 500001
#define INF 987654321

int prv[N_MAX];
int selected[N_MAX];
bool checked[N_MAX];

int main() {
    int n, ans = 0; scanf("%d", &n);
    vector<int> v(n + 1), a(n + 1);
    vector<pair<int, int>> temp;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        temp.push_back({ x, y });
    }

    sort(temp.begin(), temp.end());

    for (int i = 0; i < n; i++) {
        selected[temp[i].second] = temp[i].first;
        v[i + 1] = temp[i].second;
        a[i + 1] = INF;
    }

    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        auto low = lower_bound(a.begin(), a.end(), v[i]);
        int idx = low - a.begin();
        int t = a[idx - 1];
        a[idx] = v[i];
        if (ans < idx) {
            ans = idx;
        }
        prv[a[idx]] = t;
    }

    printf("%d\n", n - ans);
    for (int i = a[ans]; i != 0; i = prv[i]) {
        checked[selected[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!checked[temp[i].first]) {
            printf("%d\n", temp[i].first);
        }
    }

    return 0;
}