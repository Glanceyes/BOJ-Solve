#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num, ans;

int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        int input; scanf("%d", &input);
        num.push_back(input);
    }

    sort(num.begin(), num.end());

    int prev = num[1] - num[0];
    for (int i = 1; i < n - 1; i += 1) {
        prev = gcd(num[i + 1] - num[i], prev);
    }

    for (int i = 2; i * i <= prev; i += 1) {
        if (prev % i == 0) {
            ans.push_back(i);
            if (i < prev / i) {
                ans.push_back(prev / i);
            }
        }
    }
    ans.push_back(prev);

    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i += 1) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}