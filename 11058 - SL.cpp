#include <iostream>
using namespace std;
long long d[1001];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        for (int j = 1; j <= i - 3; j++) {
            long long cur = d[i - j - 2] * (j + 1);
            if (cur > d[i]) {
                d[i] = cur;
            }
        }
    }
    for (int i = 1; i <= n; i += 1) {
        cout << d[i] << '\n';
    }
    return 0;
}