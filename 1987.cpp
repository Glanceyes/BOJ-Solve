#include <cstdio>

using namespace std;

#define MAX 20

int r, c, max;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int visit[MAX][MAX];
char board[MAX][MAX];
bool alphabet[26];
bool check[MAX][MAX];

void find(int x, int y) {
    for (int i = 0; i < 4; i += 1) {
        int tempx = x + dx[i];
        int tempy = y + dy[i];
        if (tempx >= 0 && tempx < r &&
            tempy >= 0 && tempy < c) {
            if (!check[tempx][tempy] && 
                !alphabet[board[tempx][tempy] - 'A']) {           
                check[tempx][tempy] = true;
                visit[tempx][tempy] = visit[x][y] + 1;
                alphabet[board[tempx][tempy] - 'A'] = true;

                find(tempx, tempy);

                check[tempx][tempy] = false; 
                visit[tempx][tempy] = 0;
                alphabet[board[tempx][tempy] - 'A'] = false;
            }
        }
    }
    if (max < visit[x][y]) max = visit[x][y];
}

int main() {
    scanf("%d %d", &r, &c); getchar();
    
    for (int i = 0; i < r; i += 1) {
        for (int j = 0; j < c; j += 1) {
            board[i][j] = getchar();
        }
        getchar();
    }

    alphabet[board[0][0] - 'A'] = true;
    visit[0][0] = 1;

    find(0, 0);
    printf("%d\n", max);

    return 0;
}