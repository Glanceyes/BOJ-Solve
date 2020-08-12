#include <cstdio>
#include <vector>
using namespace std;

int n, m, ans;
vector<int> v;

void find(int start, int idx, int sum) {
    if (idx >= 3) {
        if (sum <= m && ans < sum) {
            ans = sum;
        }
        return;
    }
    for (int i = start; i < (int)v.size(); i += 1) {
        find(i + 1, idx + 1, sum + v[i]);
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i += 1) {
        int input; scanf("%d", &input);
        v.push_back(input);
    }
    find(0, 0, 0);
    printf("%d\n", ans);
}