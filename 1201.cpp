#include <cstdio>
#include <vector>
using namespace std;

int n, m, k;
vector<int> v, t[500];

int main() {
    scanf("%d %d %d", &n, &m, &k);

    if (n < m + k - 1 || n > m * k) {
        printf("-1\n"); return 0;
    }

    for (int i = n - m + 1; i <= n; i += 1) {
        v.push_back(i);
    }

    for (int i = 0, cnt = 1; i < m && cnt <= n - m; i += 1){
        for (int j = 0; j < k - 1; j += 1) {
            if (cnt > n - m) break;
            t[i].push_back(cnt); cnt += 1;
        }
    }

    for (int i = 0; i < m; i += 1) {
        printf("%d ", v[i]);
        while (!t[i].empty()) {
            printf("%d ", t[i].back());
            t[i].pop_back();
        }
    }
    printf("\n");

    return 0;
}