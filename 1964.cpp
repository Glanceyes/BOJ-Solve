#include <cstdio>
using namespace std;

int n, answer;

int main() {
    scanf("%d", &n);

    answer = 5;

    for (int i = 2; i <= n; i += 1) {
        answer += (i * 3 + 1);
        answer %= 45678;
    }
    printf("%d\n", answer % 45678);

    return 0;
}