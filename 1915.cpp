#include <cstdio>
using namespace std;

#define n_max 1000
#define m_max 1000
#define min(a, b) (((a) < (b) ? (a) : (b)))

int n, m, result;
int dist[n_max][m_max][2];
bool mat[n_max][m_max];

int main() {
    scanf("%d %d", &n, &m); getchar();
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            mat[i][j] = (int)(getchar() - '0');
        }
        getchar();
    }

    for (int i = n - 1; i >= 0; i -= 1) {
        int temp = 0;
        for (int j = m - 1; j >= 0; j -= 1) {
            switch (mat[i][j]) {
            case true:
                dist[i][j][0] = temp; 
                temp += 1; break;
            case false:
                dist[i][j][0] = -1;
                temp = 0; break;
            }
        }
    }

    for (int j = m - 1; j >= 0; j -= 1) {
        int temp = 0;
        for (int i = n - 1; i >= 0; i -= 1) {
            switch (mat[i][j]) {
            case true:
                dist[i][j][1] = temp;
                temp += 1; break;
            case false:
                dist[i][j][1] = -1;
                temp = 0; break;
            }
        }
    }

    /*
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            printf("(¡æ %d, ¡é %d)  ", dist[i][j][0], dist[i][j][1]);
        }
        printf("\n");
    }
    */

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (!mat[i][j]) continue;
            int limit = min(dist[i][j][0], dist[i][j][1]);
            int length = 0; bool flag = true;
            for (int k = result; k <= limit; k += 1) {
                if (dist[i + k][j][0] >= k &&
                    dist[i][j + k][1] >= k &&
                    mat[i + k][j + k]) {
                    for (; length <= k; length += 1) {
                        if (dist[i + length][j][0] < k) {
                            flag = false;
                        }
                    }
                    if (flag) {
                        result = k + 1;
                        //printf("(%d %d) -> %d\n", i, j, result);
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }

    printf("%d\n", result * result);

    return 0;
}