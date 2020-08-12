#include <cstdio>
#include <vector>
using namespace std;

int n, m, ans;
vector<int> lesson;

void find(int left, int right) {
    if (left > right) return;
    int mid = left + (right - left) / 2;

    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i += 1) {
        if (sum + lesson[i] <= mid) {
            sum += lesson[i];
        }
        else {
            if (lesson[i] > mid) {
                find(mid + 1, right); return;
            }
            else {
                cnt += 1; sum = lesson[i];
            }
        }
    }

    if (sum) {
        cnt += 1;
    }

    if (cnt > m) {
        find(mid + 1, right);
    }
    else {
        ans = mid;
        find(left, mid - 1);
    }

    return;
}

int main() {
    scanf("%d %d", &n, &m);

    int left = 1, right = 0;
    for (int i = 0; i < n; i += 1) {
        int input; scanf("%d", &input);
        lesson.push_back(input); right += input;
    }

    find(left, right);
    printf("%d\n", ans);

    return 0;
}