#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
char board[50][50];

int go_check1(int start_x, int start_y) {
    if (start_x + 7 >= n || start_y + 7 >= m) return -1;

    int cnt = 0;

    for (int i = start_x; i < start_x + 8; i++) {
        for (int j = start_y; j < start_y + 8; j++) {
            if ((i + j) % 2) {
                if (board[i][j] == 'W') cnt += 1;
            }
            else {
                if (board[i][j] == 'B') cnt += 1;
            }
        }
    }
    return cnt;
}

int go_check2(int start_x, int start_y) {
    if (start_x + 7 >= n || start_y + 7 >= m) return -1;

    int cnt = 0;

    for (int i = start_x; i < start_x + 8; i++) {
        for (int j = start_y; j < start_y + 8; j++) {
            if ((i + j) % 2) {
                if (board[i][j] == 'B') cnt += 1;
            }
            else {
                if (board[i][j] == 'W') cnt += 1;
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d", &n, &m); getchar();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = getchar();
        }
        getchar();
    }

    int ans = 64;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp1 = go_check1(i, j);
            if (temp1 != -1) {
                ans = min(ans, temp1);
            }
            int temp2 = go_check2(i, j);
            if (temp2 != -1) {
                ans = min(ans, temp2);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}