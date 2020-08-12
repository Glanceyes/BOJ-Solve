#include <cstdio>
using namespace std;

int a, b, c;
int result;
int digit[10];

int main() {
    scanf("%d %d %d", &a, &b, &c);

    result = (a * b * c);

    while (result / 10) {
        digit[result % 10] += 1;
        result /= 10;
    }
    digit[result] += 1;

    for (int i = 0; i < 10; i += 1) {
        printf("%d\n", digit[i]);
    }

    return 0;
}