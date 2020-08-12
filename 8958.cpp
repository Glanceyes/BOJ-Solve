#include <cstdio>
using namespace std;

int n;

int main() {
    scanf("%d\n", &n);

    while (n--) {
        char c; int sum = 0, cnt = 0;
        while ((c = getchar()) != '\n') {
            if (c == 'O') {
                cnt += 1; sum += cnt;
            }
            else {
                cnt = 0;
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}