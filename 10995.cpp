#include <cstdio>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            if (i % 2 == 0) {
                printf("* ");
            }
            else {
                printf(" *");
            }
        }
        printf("\n");
    }
    return 0;
}