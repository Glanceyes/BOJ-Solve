#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, ans;
vector<int> dot;

void find(int left, int right) {
    if (left > right) return;
    int mid = left + (right - left) / 2;

    int cnt = 1, prev = dot[0];
    for (int i = 1; i < n; i += 1) {
        if (dot[i] - prev >= mid) {
            cnt += 1;
            prev = dot[i];
        }
    }

    if (cnt < c) {
        find(left, mid - 1);
    }
    else {
        ans = mid;
        find(mid + 1, right);
    }
}

int main() {
    scanf("%d %d", &n, &c);

    int max_dot = 0;
    for (int i = 0; i < n; i += 1) {
        int input; scanf("%d", &input);
        dot.push_back(input);
        if (max_dot < input) {
            max_dot = input;
        }
    }
    sort(dot.begin(), dot.end());

    find(1, max_dot);
    printf("%d\n", ans);

    return 0;
}