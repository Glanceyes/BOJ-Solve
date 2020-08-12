#include <cstdio>
using namespace std;

#define T_MAX 1000

int k, c ,d;
int m[T_MAX][8];

void clockwise(int dir, int num) {
    int save;
    if (dir == -1) {
        save = m[num][0];
        for (int i = 0; i < 7; i += 1) {
            m[num][i] = m[num][i + 1];
        }
        m[num][7] = save;
    }
    if (dir == 1) {
        save = m[num][7];
        for (int i = 7; i > 0; i -= 1) {
            m[num][i] = m[num][i - 1];
        }
        m[num][0] = save;
    }
    return;
}

int main() {
    for (int i = 0; i < 4; i += 1) {
        for (int j = 0; j < 8; j += 1) {
            m[i][j] = (int)(getchar() - '0');
        }
        getchar();
    }
    scanf("%d", &k);

    int m0r, m1l, m1r, m2l, m2r, m3l;

    while (k--) {
        scanf("%d %d", &c, &d); c -= 1;
        m0r = m[0][2]; m3l = m[3][6];
        m1l = m[1][6]; m1r = m[1][2];
        m2l = m[2][6]; m2r = m[2][2];

        switch (c) {
        case 0:
            clockwise(d, 0);
            if (m0r == m1l) continue;
            clockwise(-d, 1);
            if (m1r == m2l) continue;
            clockwise(d, 2);
            if (m2r == m3l) continue;
            clockwise(-d, 3);
            break;
        case 1:
            clockwise(d, 1);
            if (m1l != m0r) {
                clockwise(-d, 0);
            }
            if (m1r == m2l) continue;
            clockwise(-d, 2);
            if (m2r == m3l) continue;
            clockwise(d, 3);
            break;
        case 2:
            clockwise(d, 2);
            if (m2r != m3l) {
                clockwise(-d, 3);
            }
            if (m1r == m2l) continue;
            clockwise(-d, 1);
            if (m0r == m1l) continue;
            clockwise(d, 0);
            break;
        case 3:
            clockwise(d, 3);
            if (m2r == m3l) continue;
            clockwise(-d, 2);
            if (m1r == m2l) continue;
            clockwise(d, 1);
            if (m0r == m1l) continue;
            clockwise(-d, 0);
            break;
        }
    }

    int sum = 0, temp = 1;
    for (int i = 0; i < 4; i += 1) {
        sum += ((!m[i][0]) ? 0 : temp);
        temp *= 2;
    }
    printf("%d\n", sum);

    return 0;
}