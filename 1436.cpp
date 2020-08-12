#include <cstdio>
using namespace std;

int n, cnt = 1;

int main() {
    scanf("%d", &n);
    int start = 666;

    while (cnt < n) {
        start += 1;
        int temp = start;
        int sixnum = 0;
        while (temp) {
            if (temp % 10 == 6) {
                sixnum += 1;
            }
            else if (sixnum < 3) {
                sixnum = 0;
            }
            temp /= 10;
        }
        if (sixnum >= 3) {
            cnt += 1;
        }
    }
    
    printf("%d\n", start);

    return 0;
}