#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    scanf("%d", &n);

    vector<int> a(n), s;

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &a[i]);
    }

    s.push_back(a[0]);

    for (int i = 1; i < n; i += 1) {
        if (s.back() < a[i]) {
            s.push_back(a[i]);
        }
        else {
            auto iter = lower_bound(s.begin(), s.end(), a[i]);
            *iter = a[i];
        }
    }
    printf("%d\n", (int)s.size());

    return 0;
}