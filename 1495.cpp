#include <cstdio>
using namespace std;

#define N_MAX 100
#define M_MAX 1000
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int n, s, m;
int v[N_MAX + 1];
bool d[N_MAX + 1][M_MAX + 1];

int main() {
    scanf("%d %d %d", &n, &s, &m);

    for (int i = 1; i <= n; i += 1) {
        scanf("%d", &v[i]);
    }

    d[0][s] = true;
    for (int i = 1; i <= n; i += 1) {
        for (int j = 0; j <= m; j += 1) {
            if (j + v[i] <= m) {
                d[i][j] = d[i][j] || d[i - 1][j + v[i]];
            }
            if (j - v[i] >= 0) {
                d[i][j] = d[i][j] || d[i - 1][j - v[i]];
            }
        }
    }

    int temp = m;
    while (!d[n][temp] && temp >= 0) {
        temp -= 1;
    }
    printf("%d\n", temp);

    return 0;
}