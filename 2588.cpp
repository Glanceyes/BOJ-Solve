#include <cstdio>

using namespace std;

int main() {
    int a, b, temp, result = 0;
    scanf("%d\n%d", &a, &b);
    printf("%d\n", (temp = a * (b % 10)));
    result += temp;
    printf("%d\n", (temp = a * ((b / 10) % 10)));
    result += (temp * 10);
    printf("%d\n", (temp = a * ((b / 100) % 10)));
    result += (temp * 100);
    printf("%d\n", result);
    return 0;
}