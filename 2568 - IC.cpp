#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define V_MAX 500000
#define INF 987654321

vector<int> stick_a(V_MAX + 1), stick_b(V_MAX + 1);
vector<int> idx(V_MAX + 1), check(V_MAX + 1, INF), prv(V_MAX + 1);

int main() {
    int n; scanf("%d", &n);
    vector<pair<int, int>> temp;

    int max_num = 0;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        temp.push_back({ x, y });
        stick_a[i] = x;
        idx[stick_a[i]] = i;
        if (max_num < x) {
            max_num = x;
        }
    }

    for (int i = 1; i <= max_num; i++) {
        if (idx[i] == 0) {
            idx[i] = i;
        }
    }

    for (int i = 0; i < n; i++) {
        int x = temp[i].first;
        int y = temp[i].second;
        stick_b[i + 1] = idx[y];
    }

    printf("\nstick_b\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", stick_b[i]);
    }
    printf("\n");

    check[0] = 0; int ans = 0;
    for (int i = 1; i <= n; i++) {
        auto pos = lower_bound(check.begin(), check.end(), stick_b[i]);
        int low = pos - check.begin();
        check[low] = stick_b[i];
        prv[check[low]] = check[low - 1];
        if (ans < low) {
            ans = low;
        }
    }

    vector<int> result;
    printf("%d\n", ans);
    for (int i = check[ans]; i > 0; i = prv[i]) {
        printf("%d ", stick_a[i]);
    }
    printf("\n");

    return 0;
}