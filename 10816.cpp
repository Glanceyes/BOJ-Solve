#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    scanf("%d", &n);
    vector<int> num(n);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &num[i]);
    }

    sort(num.begin(), num.end());

    scanf("%d", &m);
    for (int i = 0; i < m; i += 1) {
        int temp; scanf("%d", &temp);
        int left = 0, right = n - 1, mid, ans1, ans2;
        ans1 = ans2 = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (num[mid] == temp) {
                ans1 = mid;
                right = mid - 1;
            }
            else if (num[mid] > temp) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        left = 0; right = n - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (num[mid] == temp) {
                ans2 = mid;
                left = mid + 1;
            }
            else if (num[mid] > temp) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if (num[ans1] != temp) {
            printf("0 ");
        }
        else {
            printf("%d ", ans2 - ans1 + 1);
        }
    }
    printf("\n");

    return 0;
}