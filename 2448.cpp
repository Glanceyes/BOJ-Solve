#include <cstdio>
#include <string.h>
using namespace std;

int n, cnt, q;
char save[4073][8144];

int exponential(int x) {
    int v = 3;
    while (x--) {
        v *= 2;
    }
    return v;
}

void draw_star(int idx) {
    if (idx == 0) {
        int start = (q - exponential(idx + 1)) / 2;
        for (int i = 0; i < 3; i += 1) {
            for (int j = start; j < start + 5; j += 1) {
                switch (i) {
                case 0:
                    if (j == start + 2) {
                        save[i][j] = '*';
                    }
                    break;
                case 1:
                    if (j == start + 1 || j == start + 3) {
                        save[i][j] = '*';
                    }
                    break;
                case 2:
                    save[i][j] = '*'; break;
                }
            }
        }
        return;
    }
    draw_star(idx - 1);

    int start1 = (q - exponential(idx + 1)) / 2;
    int start2 = (q - exponential(idx)) / 2;
    int temp1 = exponential(idx - 1), temp2 = exponential(idx);
    for (int i = temp1; i < temp1 * 2; i += 1) {
        for (int j = start1; j < start1 + temp2 - 1; j += 1) {
            save[i][j] = save[i - temp1][start2 + (j - start1)];
        }
        for (int j = start1 + temp2; j < start1 + temp2 * 2 - 1; j += 1) {
            save[i][j] = save[i - temp1][start2 + (j - start1 - temp2)];
        }
    }
}

int main() {
    scanf("%d", &n);
    memset(save, ' ', sizeof(save));

    int temp = n / 3;
    while (temp > 1) {
        temp /= 2; cnt += 1;
    }

    q = exponential(cnt + 1);

    draw_star(cnt);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < q; j += 1) {
            printf("%c", save[i][j]);
        }
        printf("\n");
    }

    return 0;
}