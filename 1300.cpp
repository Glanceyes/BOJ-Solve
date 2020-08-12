#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long n, k, ans;

int main() {
    scanf("%lld %lld", &n, &k);

    long long left = 1, right = n * n;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long cnt = 0;
        for (long long i = 1; i <= n; i += 1) {
            cnt += (n > (mid / i) ? (mid / i) : n);
        }
        if (cnt >= k) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    printf("%lld\n", ans);

    return 0;
}