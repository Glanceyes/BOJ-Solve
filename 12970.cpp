#include <cstdio>
using namespace std;

int n, k;
char s[52];

bool find(int a, int b, int m) {
    if (a + b == n) {
        if (m == k) {
            printf("%s\n", s);
            return true;
        }
        else {
            return false;
        }
    }

    s[a + b] = 'A';
    if (find(a + 1, b, m)) {
        return true;
    }

    s[a + b] = 'B';
    if (m + a > k) return false;
    if (find(a, b + 1, m + a)) {
        return true;
    }

    return false;
}

int main() {
    int temp = 0;
    scanf("%d %d", &n, &k);

    temp = (n % 2 == 0) ? ((n / 2) * (n / 2)) : ((n / 2) * (n / 2 + 1));

    if (temp < k) {
        printf("-1\n");
    }
    else {
        find(0, 0, 0);
    }

    return 0;
}