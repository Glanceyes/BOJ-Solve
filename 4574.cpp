#include <cstdio>
#include <string.h>
using namespace std;

int n;
int mat[10][10];

bool row[10][10];
bool col[10][10];
bool square[4][4][10];
bool domino[10][10];

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

int square_index(int v) {
    return ((v - 1) / 3 + 1);
}

bool find(int x, int y) {
    if (x >= 9 && y >= 9) {
        return true;
    }

    if (y >= 10) { x += 1; y = 1; }

    if (mat[x][y]) {
        if (find(x, y + 1)) {
            return true;
        }
    }
    else {
        for (int k = 0; k < 2; k += 1) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 1 && nx < 10 && ny >= 1 && ny < 10) {
                if (!mat[nx][ny]) {
                    for (int l = 1; l < 10; l += 1) {
                        if (!row[x][l] && !col[y][l] &&
                            !square[square_index(x)][(y - 1) / 3 + 1][l]) {
                            for (int m = 1; m < 10; m += 1) {
                                if (l == m || (domino[l][m] || domino[m][l])) continue;
                                if (!row[nx][m] && !col[ny][m] &&
                                    !square[square_index(nx)][(ny - 1) / 3 + 1][m]) {
                                    mat[x][y] = l; mat[nx][ny] = m;
                                    row[x][l] = col[y][l] = true;
                                    row[nx][m] = col[ny][m] = true;
                                    square[square_index(x)][square_index(y)][l] = true;
                                    square[square_index(nx)][square_index(ny)][m] = true;
                                    domino[l][m] = true;
                                    if (find(x, y + 1)) {
                                        return true;
                                    }
                                    mat[x][y] = 0; mat[nx][ny] = 0;
                                    row[x][l] = col[y][l] = false;
                                    row[nx][m] = col[ny][m] = false;
                                    square[square_index(x)][square_index(y)][l] = false;
                                    square[square_index(nx)][square_index(ny)][m] = false;
                                    domino[l][m] = false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
     
    return false;
}

int main() {
    int cnt = 1;
    while (1) {
        memset(mat, 0, sizeof(mat));
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(square, false, sizeof(square));
        memset(domino, false, sizeof(domino));

        scanf("%d", &n); if (!n) break;

        for (int i = 0; i < n; i += 1) {
            int v1, v2, row1, row2, col1, col2;
            char c_row1, c_row2;
            scanf("%d %c%d", &v1, &c_row1, &col1);
            scanf("%d %c%d", &v2, &c_row2, &col2);
            row1 = (int)(c_row1 - 'A') + 1;
            row2 = (int)(c_row2 - 'A') + 1;
            mat[row1][col1] = v1;
            mat[row2][col2] = v2;
            row[row1][v1] = row[row2][v2] = true;
            col[col1][v1] = col[col2][v2] = true;
            square[square_index(row1)][square_index(col1)][v1] = true;
            square[square_index(row2)][square_index(col2)][v2] = true;
            domino[v1][v2] = domino[v2][v1] = true;
        }
        getchar();
        for (int i = 1; i <= 9; i += 1) {
            char c_row; int t_row, t_col;
            scanf("%c%d", &c_row, &t_col); getchar();
            t_row = (int)(c_row - 'A') + 1;
            mat[t_row][t_col] = i;
            row[t_row][i] = col[t_col][i] = true;
            square[square_index(t_row)][square_index(t_col)][i] = true;
        }

        find(1, 1);

        printf("Puzzle %d\n", cnt); cnt += 1;
        for (int i = 1; i < 10; i += 1) {
            for (int j = 1; j < 10; j += 1) {
                printf("%d", mat[i][j]);
            }
            printf("\n");
        }
    }


    return 0;
}