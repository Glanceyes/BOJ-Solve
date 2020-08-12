#include <cstdio>
using namespace std;

bool possible[10001];

int main() {
    for (int i = 1; i <= 10000; i += 1) {
        for (int j = i; j <= 10000;) {
            int temp = j;
            while (temp / 10) {
                j += (temp % 10);
                temp /= 10;
            }
            j += temp; possible[j] = true;
        }
    }
    for (int i = 1; i <= 10000; i += 1) {
        if (!possible[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}