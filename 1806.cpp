#include <cstdio>

using namespace std;

#define MAX 100000

int main() {
    int n, min = MAX;
    bool flag = false;
    long long m, sum;

    int a[MAX];
    int left, right, len;
    scanf("%d %lld", &n, &m);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &a[i]);
    }

    left = right = 0; sum = a[0], len = 1;

    while (left <= right && right < n) {
        if (sum < m) {
            len += 1;
            right += 1;
            sum += a[right];
        }
        else if (sum >= m) {
            flag = true;
            if (min > len) {
                min = len;
            }
            len -= 1;
            sum -= a[left];
            left += 1;
            if (left > right && left < n) {
                len = 1;
                right = left;
                sum += a[right];
            }
        }
    }
    
    if (flag) {
        printf("%d\n", min);
    }
    else {
        printf("0\n");
    }

    return 0;
}