#include <cstdio>
#include <string.h>
using namespace std;

char str[5][15];

int main() {
    memset(str, '\0', sizeof(str));
    for (int i = 0; i < 5; i += 1) {
        char c; int j = 0;
        while ((c = getchar()) != '\n') {
            str[i][j] = c; j += 1;
        }
    }

    for (int j = 0; j < 15; j += 1) {
        for (int i = 0; i < 5; i += 1) {
            if (str[i][j] != '\0') {
                printf("%c", str[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}