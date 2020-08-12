#include <cstdio>
using namespace std;

#define MAX 100

int n;
int jump[MAX][MAX];
long long visit[MAX][MAX];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            scanf("%d", &jump[i][j]);
        }
    }
    
    visit[0][0] = 1;

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            int d = jump[i][j];
            if (!d) continue;
            int x, y;
            for (int k = 0; k < 2; k += 1) {
                if (!k) {
                    x = i + d; y = j;
                }
                else {
                    x = i; y = j + d;
                }
                if (x < n && y < n) {
                    visit[x][y] += visit[i][j];
                }
            }
        }
    }

    printf("%lld\n", visit[n - 1][n - 1]);

    return 0;
}