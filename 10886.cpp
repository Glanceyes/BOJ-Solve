#include <cstdio>
using namespace std;

int n, num;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        int temp; scanf("%d", &temp);
        if (temp) { num += 1; };
    }
    if ((n - num) > num) {
        printf("Junhee is not cute!\n");
    }
    else {
        printf("Junhee is cute!\n");
    }

    return 0;
}