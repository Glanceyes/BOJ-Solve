#include <cstdio>
using namespace std;

typedef struct Camera {
    int x = 0;
    int y = 0;
    int num = 0;
}camera;

camera c[8];
int n, m;
int camnum, blank;
int answer = -1;
int map[8][8];
int see[8][8];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1 ,0 };

int go(int idx, int x, int y, int d, int cnt, int cn, bool clean) {
    if (!(x >= 0 && x < n && y >= 0 && y < m)) return cnt;
    if (map[x][y] == 6) return cnt;

    int nx = x + dx[d], ny = y + dy[d], result = cnt;

    if (!clean) {
        bool flag = false;
        if (!see[x][y]) {
            see[x][y] = idx;
            flag = true;
        }

        if (flag) {
            result = go(idx, nx, ny, d, cnt + 1, cn, clean);
        }
        else {
            result = go(idx, nx, ny, d, cnt, cn, clean);
        }
    }
    else {
        go(idx, nx, ny, d, cnt + 1, cn, clean);
        if (see[x][y] == idx) {
            see[x][y] = 0;
        }
    }
    return result;
}

int cam(int idx, int cn, int x, int y, int d, bool clean) {
    int result = 0;
    switch (cn) {
    case 5:
    case 4:
    case 3:
        for (int i = 0; i < cn - 1; i += 1) {
            result += go(idx, x, y, d, 0, cn, clean); d -= 1;
            if (d < 0) d = 3;
        }
        break;
    case 2:
        result += go(idx, x, y, d + 2, 0, cn, clean);
    case 1:
        result += go(idx, x, y, d, 0, cn, clean);
        break;
    }
    return result;
}

void find(int idx, int sum) {
    if (idx == camnum) {
        if (answer == -1 || answer > blank - sum) {
            answer = blank - sum;
        }
        return;
    }
    int start = 4;
    if (c[idx].num == 2) {
        start = 2;
    }
    if (c[idx].num == 5) {
        start = 1;
    }
    for (int i = 0, temp = 0; i < start; i += 1) {
        temp = sum + cam(idx + 1, c[idx].num, c[idx].x, c[idx].y, i, false);
        find(idx + 1, temp);
        cam(idx + 1, c[idx].num, c[idx].x, c[idx].y, i, true);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            scanf("%d", &map[i][j]);
            if (map[i][j] != 6) {
                blank += 1;
            }
            if (map[i][j] >= 1 && map[i][j] <= 5) {
                c[camnum].x = i; c[camnum].y = j;
                c[camnum].num = map[i][j]; camnum += 1;
            }
        }
    }

    find(0, 0);
    printf("%d\n", answer);

    return 0;
}