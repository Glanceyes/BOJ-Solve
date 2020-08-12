#include <cstdio>
using namespace std;

#define n_max 100
#define m_max 500
#define abs(x) (((x) > 0) ? (x) : (-(x)))

int n, m, a, b, x, y;
int s[m_max];
int d[m_max + 1][n_max + 1];

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &a, &b, &x, &y);

    for (int i = 1; i <= m; i += 1) {
        scanf("%d", &s[i]);
    }
    
    for (int i = 0; i <= m; i += 1) {
        for (int j = 0; j <= n; j += 1) {
            d[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i += 1) {
        if (i == a) {
            d[0][i] = 0;
        }
        else {
            d[0][i] = abs(a - i) * y;
        }
    }

    for (int i = 1; i <= m; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            for (int k = 1; k <= n; k += 1) {
                int temp = 0;
                if (k == j && ((k - 1) == s[i] || k == s[i])) {
                    temp = d[i - 1][k] + x;
                    if (d[i][j] == -1 || d[i][j] > temp) {
                        d[i][j] = temp;
                    }
                }
                else if ((j <= s[i] && s[i] <= (k - 1)) ||
                    (k <= s[i] && s[i] <= (j - 1))) {
                    temp = d[i - 1][k] + (abs(j - k) - 1) * y;
                    if (d[i][j] == -1 || d[i][j] > temp) {
                        d[i][j] = temp;
                    }
                }
                else {
                    temp = d[i - 1][k] + abs(j - k) * y;
                    if (d[i][j] == -1 || d[i][j] > temp) {
                        d[i][j] = temp;
                    }
                }
            }
        }
    }
    printf("%d\n", d[m][b]);

    return 0;
}