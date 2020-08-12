#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int main() {
    int n; scanf("%d", &n);
    vector<int> t1(n + 1), t2(n + 1);
    vector<int> v(n + 1), a(n + 1), prev(n + 1);
    for (int i = 1; i <= n; i++) {
        int val; scanf("%d", &val);
        t1[val] = i; t2[i] = val;
    }
    for (int i = 1; i <= n; i++) {
        int val; scanf("%d", &val);
        v[i] = t1[val];
        a[i] = INF;
        prev[i] = -1;
    }

    a[0] = 0; int ans = 0;
    for (int i = 1; i <= n; i++) {
        vector<int>::iterator low;
        low = lower_bound(a.begin(), a.end(), v[i]);
        int idx = low - a.begin();
        int temp1 = a[idx - 1];
        a[idx] = v[i];
        if (ans < idx) {
            ans = idx;
        }
        prev[a[idx]] = temp1;
    }
    
    vector<int> result;
    for (int i = a[ans]; i != 0; i = prev[i]) {
        result.push_back(t2[i]);
    }
    sort(result.begin(), result.end());

    printf("%d\n", ans);
    for (int i = 0; i < (int)result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    

    return 0;
}