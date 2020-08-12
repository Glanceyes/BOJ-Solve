#include <cstdio>
#include <vector>
using namespace std;

long long n, m, ans, k;
vector<long long> v;

int main() {
    scanf("%lld %lld", &n, &m);

    for (long long i = 0; i < m; i += 1) {
        long long input; scanf("%lld", &input);
        v.push_back(input); k += 1;
    }

    long long left = 1, right = 100000000000;
    while (left <= right) {
        long long mid = left + (right - left) / 2, sum = 0;
        for (long long i = 0; i < k; i += 1) {
            if ((mid - 1) % v[i]) {
                sum += ((mid - 1) / v[i] + 1);
            }
            else {
                sum += (mid - 1) / v[i];
            }
        }
        for (long long i = 0; i < k; i += 1) {
            if ((mid - 1) % v[i] == 0 || n <= m) {
                sum += 1;
                if (sum == n) {
                    ans = (i + 1);
                    printf("%lld\n", ans);
                    return 0;
                }
            }
        }
        if (sum < n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}