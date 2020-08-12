#include <cstdio>
using namespace std;

int m, cup[4];

int main() {
    scanf("%d", &m);
    
    for (int i = 1; i <= 3; i += 1) {
        cup[i] = i;
    }

    while (m--) {
        int x, y, temp;
        scanf("%d %d", &x, &y);
        temp = cup[x];
        cup[x] = cup[y];
        cup[y] = temp;
    }
    for (int i = 1; i <= 3; i += 1) {
        if (cup[i] == 1) {
            printf("%d\n", i); break;
        }
    }

    return 0;
}