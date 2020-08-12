#include <cstdio>
using namespace std;

int l, result;

int main() {
    scanf("%d", &l);

    result = l / 5;
    if (l % 5) {
        result += 1;
    }

    printf("%d\n", result);

    return 0;
}