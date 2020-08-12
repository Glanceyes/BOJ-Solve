#include <cstdio>
using namespace std;

#define T_MAX 1000

int t, k, c, d;
int s[T_MAX][2];
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
    scanf("%d\n", &t);
    for (int i = 0; i < t; i += 1) {
        for (int j = 0; j < 8; j += 1) {
            m[i][j] = (int)(getchar() - '0');
        }
        getchar();
    }
    scanf("%d", &k);

    while (k--) {
        scanf("%d %d", &c, &d); c -= 1;
        for (int i = 0; i < t; i += 1) {
            s[i][0] = m[i][2];
            s[i][1] = m[i][6];
        }
        clockwise(d, c);
        for (int s1 = c - 1, d1 = d * -1; s1 >= 0; s1 -= 1, d1 *= -1) {
            if (s[s1][0] == s[s1 + 1][1]) break;
            clockwise(d1, s1);
        }
        
        for (int s2 = c + 1, d2 = d * -1; s2 < t; s2 += 1, d2 *= -1) {
            if (s[s2][1] == s[s2 - 1][0]) break;
            clockwise(d2, s2);
        }
    }

    int sum = 0;
    for (int i = 0; i < t; i += 1) {
        if (m[i][0]) {
            sum += 1;
        }
    }
    printf("%d\n", sum);

    return 0;
}