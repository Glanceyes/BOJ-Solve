#include <cstdio>
#include <vector>
using namespace std;

long long n, m, sum;
long long mid, ans;
vector<long long> budget;

int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        long long x; scanf("%lld", &x);
        budget.push_back(x); sum += x;
        if (x > ans) ans = x;
    }
    scanf("%lld", &m);

    if (sum <= m) {
        printf("%lld\n", ans);
    }
    else {
        long long left = 1, right = m;
        while (left <= right) {
            mid = left + ((right - left) / 2); sum = 0;
            for (auto x : budget) {
                if (x > mid) {
                    sum += mid;
                }
                else {
                    sum += x;
                }
            }

            if (sum > m) {
                right = mid - 1;
            }
            else {
                ans = mid; left = mid + 1;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}