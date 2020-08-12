#include <cstdio>
#include <cstring>
using namespace std;

int n;
char m[2200][2200];

int three_exp(int x) {
    int exp = 0;
    while (x > 1) {
        x /= 3;
        exp += 1;
    }
    return exp;
}

void draw(int idx, int start_x, int end_x, int start_y, int end_y) {
    if (idx == 1) {
        for (int i = start_x; i < end_x; i += 1) {
            for (int j = start_y; j < end_y; j += 1) {
                if (i == start_x + 1 && j == start_y + 1) {
                    continue;
                }
                m[i][j] = '*';
            }
        }
        return;
    }
    int dx = (end_x - start_x + 1) / 3;
    int dy = (end_y - start_y + 1) / 3;
    int xf = start_x + dx;
    int yf = start_y + dy;

    for (int i = start_x; i < end_x; i += dx) {
        for (int j = start_y; j < end_y; j += dy) {
            if (i == xf && j == yf) {
                continue;
            }
            draw(idx - 1, i, i + dx, j, j + dy);
        }
    }
    return;
}

int main() {
    scanf("%d", &n);

    memset(m, ' ', sizeof(m));

    draw(three_exp(n), 0, n, 0, n);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}