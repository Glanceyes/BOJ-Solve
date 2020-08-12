#include <cstdio>
using namespace std;

int n, m, answer;
int a[50][50], b[50][50];

int main() {
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            a[i][j] = (int)(getchar() - '0');
        }
        getchar();
    }
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            b[i][j] = (int)(getchar() - '0');
        }
        getchar();
    }
    
    for (int i = 0; i < n - 2; i += 1) {
        for (int j = 0; j < m - 2; j += 1) {
            if (a[i][j] == b[i][j]) continue;
            for (int k = i; k <= i + 2; k += 1) {
                for (int l = j; l <= j + 2; l += 1) {
                    a[k][l] = 1 - a[k][l];
                }
            }
            answer += 1;
        }
    }

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (a[i][j] != b[i][j]) {
                printf("-1\n"); return 0;
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}