#include <cstdio>
#include <queue>

using namespace std;

#define MAX 102

int t, h, w;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int open1[MAX][MAX];
int open2[MAX][MAX];
int open3[MAX][MAX];
char map[MAX][MAX];

void find(pair<int, int> prisoner1, pair<int, int> prisoner2) {
    queue<pair<int, int>> q1, q2, q3;
    q1.push(prisoner1); q2.push(prisoner2);

    int outx = 1, outy = 2, dir = 0;
    while (dir < 4) {
        if (map[outx][outy] != '*') {
            q3.push(make_pair(outx, outy));
            if (map[outx][outy] == '#') {
                open3[outx][outy] = 1;
            }
            else {
                open3[outx][outy] = 0;
            }
        }
        outx += dx[dir]; outy += dy[dir];
        if (!(outx >= 1 && outx < h + 1 && outy >= 1 && outy < w + 1)) {
            outx -= dx[dir]; outy -= dy[dir]; dir += 1;
        }
    }

    open1[prisoner1.first][prisoner1.second] = 0;
    open2[prisoner2.first][prisoner2.second] = 0;
    while (!(q1.empty() && q2.empty() && q3.empty())) {
        int tmpx, tmpy, nx1, ny1, nx2, ny2, nx3, ny3;
        queue<pair<int, int>> nxt_q1, nxt_q2, nxt_q3;
        while (!q1.empty()) {
            nx1 = q1.front().first;
            ny1 = q1.front().second;
            q1.pop();

            for (int i = 0; i < 4; i += 1) {
                tmpx = nx1 + dx[i];
                tmpy = ny1 + dy[i];
                if (tmpx >= 0 && tmpx < h + 2 && tmpy >= 0 && tmpy < w + 2) {
                    if (map[tmpx][tmpy] != '*') {
                        if (map[tmpx][tmpy] == '#') {
                            if (open1[tmpx][tmpy] > open1[nx1][ny1] + 1) {
                                open1[tmpx][tmpy] = open1[nx1][ny1] + 1;
                                nxt_q1.push(make_pair(tmpx, tmpy));
                            }
                        }
                        else {
                            if (open1[tmpx][tmpy] > open1[nx1][ny1]) {
                                open1[tmpx][tmpy] = open1[nx1][ny1];
                                nxt_q1.push(make_pair(tmpx, tmpy));
                            }
                        }
                    }
                }
            }
        }

        while (!q2.empty()) {
            nx2 = q2.front().first;
            ny2 = q2.front().second;
            q2.pop();

            for (int i = 0; i < 4; i += 1) {
                tmpx = nx2 + dx[i];
                tmpy = ny2 + dy[i];
                if (tmpx >= 0 && tmpx < h + 2 && tmpy >= 0 && tmpy < w + 2) {
                    if (map[tmpx][tmpy] != '*') {
                        if (map[tmpx][tmpy] == '#') {
                            if (open2[tmpx][tmpy] > open2[nx2][ny2] + 1) {
                                open2[tmpx][tmpy] = open2[nx2][ny2] + 1;
                                nxt_q2.push(make_pair(tmpx, tmpy));
                            }
                        }
                        else {
                            if (open2[tmpx][tmpy] > open2[nx2][ny2]) {
                                open2[tmpx][tmpy] = open2[nx2][ny2];
                                nxt_q2.push(make_pair(tmpx, tmpy));
                            }
                        }
                    }
                }
            }
        }

        while (!q3.empty()) {
            nx3 = q3.front().first;
            ny3 = q3.front().second;
            q3.pop();

            for (int i = 0; i < 4; i += 1) {
                tmpx = nx3 + dx[i];
                tmpy = ny3 + dy[i];
                if (tmpx >= 0 && tmpx < h + 2 && tmpy >= 0 && tmpy < w + 2) {
                    if (map[tmpx][tmpy] != '*') {
                        if (map[tmpx][tmpy] == '#') {
                            if (open3[tmpx][tmpy] > open3[nx3][ny3] + 1) {
                                open3[tmpx][tmpy] = open3[nx3][ny3] + 1;
                                nxt_q3.push(make_pair(tmpx, tmpy));
                            }
                        }
                        else {
                            if (open3[tmpx][tmpy] > open3[nx3][ny3]) {
                                open3[tmpx][tmpy] = open3[nx3][ny3];
                                nxt_q3.push(make_pair(tmpx, tmpy));
                            }
                        }
                    }
                }
            }
        }
        q1 = nxt_q1; q2 = nxt_q2; q3 = nxt_q3;
    }

    return;
}

int main() {
    int x1, y1, x2, y2;
    scanf("%d", &t);

    while (t--) {
        x1 = y1 = x2 = y2 = -1;
        for (int i = 0; i < MAX; i += 1) {
            for (int j = 0; j < MAX; j += 1) {
                open1[i][j] = open2[i][j] = open3[i][j] = MAX * MAX;
            }
        }
        scanf("%d %d", &h, &w); getchar();
        for (int i = 0; i < h + 2; i += 1) {
            for (int j = 0; j < w + 2; j += 1) {
                if (i == 0 || i == h + 1 ||
                    j == 0 || j == w + 1) {
                    map[i][j] = '.';
                }
            }
        }
        for (int i = 1; i < h + 1; i += 1) {
            for (int j = 1; j < w + 1; j += 1) {
                map[i][j] = getchar();
                if (map[i][j] == '$') {
                    if (x1 == -1) {
                        x1 = i; y1 = j;
                    }
                    else {
                        x2 = i; y2 = j;
                    }
                }
            }
            getchar();
        }
       
        find(make_pair(x1, y1), make_pair(x2, y2));

        int result = MAX * MAX * 3;
        for (int i = 0; i < h + 2; i += 1) {
            for (int j = 0; j < w + 2; j += 1) {
                if (map[i][j] == '*') {
                    continue;
                }
                int tmp = open1[i][j] + open2[i][j] + open3[i][j];
                if (map[i][j] == '#') {
                    tmp -= 2;
                }
                if (result > tmp) {
                    result = tmp;
                }
            }
        }

        printf("%d\n", result);
    }

    return 0;
}