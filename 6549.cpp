#include <cstdio>
#include <tuple>
#include <stack>
using namespace std;

long long n, h, ans;

int main() {
    while (1) {
        scanf("%lld", &n);
        if (n == 0) break;
        ans = 0;
        stack<pair<long long, long long>> s;

        for (long long i = 0; i < n; i += 1) {
            scanf("%lld", &h);
            if (s.empty()) {
                s.push(make_pair(0, h));
            }
            else {
                long long prev = i;
                while (!s.empty()) {
                    if (s.top().second < h) break;
                    long long temp = (i - s.top().first) * s.top().second;
                    prev = s.top().first;
                    if (ans < temp) {
                        ans = temp;
                    }
                    s.pop();
                }
                s.push(make_pair(prev, h));
            }
        }

        while (!s.empty()) {
            long long temp = (n - s.top().first) * s.top().second;
            if (ans < temp) {
                ans = temp;
            }
            s.pop();
        }
        printf("%lld\n", ans);
    }

    return 0;
}