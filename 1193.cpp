#include <cstdio>
using namespace std;

int x;

int main() {
    scanf("%d", &x);

    int idx = 1, sum = 0;
    
    for (int i = 1; ; i += 1) {
        if (sum + i >= x) {
            idx = i + 1; break;
        }
        sum += i;
    }

    int cnt = sum + 1;

    for (int i = 1; i < idx; i += 1) {
        if (cnt == x) {
            if (!(idx % 2)) {
                printf("%d/%d\n", idx - i, i);
            }
            else {
                printf("%d/%d\n", i, idx - i);
            }
            break;
        }
        cnt += 1;
    }

    return 0;
}