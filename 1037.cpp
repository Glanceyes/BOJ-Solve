#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, result;
vector<int> a;

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
        int tmp; scanf("%d", &tmp);
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());
    result = a[0] * a[a.size() - 1];

    printf("%d\n", result);

    return 0;
}