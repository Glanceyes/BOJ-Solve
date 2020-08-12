#include <cstdio>
#include <vector>
using namespace std;

long long n, m, ans;
vector<long long> tr;

void find(long long left, long long right) {
    if (left > right) return;
    long long mid = left + (right - left) / 2;

    long long sum = 0;
    for (long long i = 0; i < n; i += 1) {
        sum += (mid <= tr[i]) ? (tr[i] - mid) : 0;
    }
    if (sum >= m) {
        ans = mid;
        find(mid + 1, right);
    }
    else {
        find(left, mid - 1);
    }
    return;
}

int main() {
    scanf("%lld %lld", &n, &m);

    long long max_len = 0;
    for (long long i = 0; i < n; i += 1) {
        long long input; scanf("%lld", &input);
        tr.push_back(input);
        if (max_len < input) {
            max_len = input;
        }
    }

    find(1, max_len);
    printf("%lld\n", ans);

    return 0;
}