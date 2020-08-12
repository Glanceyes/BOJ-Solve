#include <cstdio>
#include <vector>
using namespace std;

long long k, n, ans;
vector<long long> lan;

void find(long long left, long long right) {
    if (left > right) return;
    long long mid = left + (right - left) / 2;

    long long cnt = 0;
    for (int i = 0; i < k; i += 1) {
        cnt += (lan[i] / mid);
    }

    if (cnt < n) {
        find(left, mid - 1);
    }
    else {
        ans = mid;
        find(mid + 1, right);
    }
}

int main() {
    scanf("%lld %lld", &k, &n);

    int max_len = 0;
    for (int i = 0; i < k; i += 1) {
        long long input; scanf("%lld", &input);
        lan.push_back(input);
        if (max_len < input) {
            max_len = input;
        }
    }

    find(1, max_len);
    printf("%lld\n", ans);

    return 0;
}