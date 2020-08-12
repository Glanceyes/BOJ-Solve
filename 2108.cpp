#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[8001];
vector<int> v, t;

int main() {
    scanf("%d", &n);
    double ma = 0; int cnt_max = 0;
    for (int i = 0; i < n; i += 1) {
        int input; scanf("%d", &input);
        v.push_back(input);
        a[input + 4000] += 1;
        ma += (double)input;
        if (cnt_max < a[input + 4000]) {
            cnt_max = a[input + 4000];
        }
    }
    sort(v.begin(), v.end());
    int mn = v[(n - 1) / 2]; ma = ma / (double)n;
    int mf = 0, mc = v[n - 1] - v[0];
    for (int i = 0; i <= 8000; i += 1) {
        if (a[i] == cnt_max) {
            t.push_back(i - 4000);
        }
    }

    if (t.size() > 1) {
        mf = t[1];
    }
    else {
        mf = t[0];
    }

    printf("%0.lf\n%d\n%d\n%d\n", ma, mn, mf, mc);

    return 0;
}