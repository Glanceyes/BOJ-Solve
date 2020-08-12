#include <cstdio>
using namespace std;

int n;

int digit(int x) {
    int cnt = 0;
    while (x) {
        cnt += 1;
        x /= 10;
    }
    return cnt;
}

bool determine(int x) {
    int d = digit(x);
    if (d >= 2) {
        int prev = (x / 10) % 10;
        int diff = (x % 10) - prev;
        int temp = x / 100;
        while (temp) {
            if (diff != prev - (temp % 10)) {
                return false;
            }
            prev = temp % 10;
            temp /= 10;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    
    int cnt = 0;
    for (int i = 1; i <= n; i += 1) {
        if (determine(i)) {
            cnt += 1;
        }
    }
    printf("%d\n", cnt);

    return 0;
}