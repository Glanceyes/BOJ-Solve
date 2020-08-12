#include <cstdio>
using namespace std;

int n, m, ans = 10000;
int num[5000];

int find(int mid) {
    int t_min, t_max, cnt = 1;
    t_min = t_max = num[0];

    for (int i = 1; i < n; i += 1) {
        if (t_min > num[i]) {
            t_min = num[i];
        }
        if (t_max < num[i]) {
            t_max = num[i];
        }
        if (t_max - t_min > mid) {
            cnt += 1; t_min = t_max = num[i];
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d", &n, &m);

    int left = 0, right = 0;

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &num[i]);
        if (right < num[i]) {
            right = num[i];
        }
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (find(mid) <= m) {
            if (ans > mid) {
                ans = mid;
            }
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}