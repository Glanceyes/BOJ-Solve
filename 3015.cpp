#include <cstdio>
#include <stack>
using namespace std;

int n;
long long ans;
stack<int> s;

int main() {
    scanf("%d", &n);

    int input, cnt = 1;

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &input);
        while (!s.empty()) {
            if (s.top() >= input) break;
            ans += 1;
            s.pop();
        }
        if (!s.empty()) {
            if (s.top() == input) {
                ans += cnt; cnt += 1;
            }
            else {
                cnt = 1;
                ans += 1;
            }
        }
        s.push(input);
    }
    while (!s.empty()) {
        s.pop();
    }

    printf("%lld\n", ans);

    return 0;
}