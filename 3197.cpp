#include <cstdio>
#include <queue>
using namespace std;

int r, c, day;
int end_x, end_y;
char map[1500][1500];
bool melt[1500][1500];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> q, sq;

void find() {
    while (!q.empty()) {
        queue<pair<int, int>> next_q;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second; q.pop();

            for (int i = 0; i < 4; i += 1) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                    if (map[nx][ny] == 'X') {
                        map[nx][ny] = '.';
                        next_q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        q = next_q; day += 1;

        queue<pair<int, int>> next_sq;
        while (!sq.empty()) {
            int x = sq.front().first;
            int y = sq.front().second; sq.pop();

            if (x == end_x && y == end_y) {
                return;
            }

            bool flag = false;
            for (int i = 0; i < 4; i += 1) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                    if (map[nx][ny] == 'X') {
                        flag = true;
                    }
                    else if (!melt[nx][ny]) {
                        melt[nx][ny] = true;
                        sq.push(make_pair(nx, ny));
                    }
                }
            }
            if (flag) {
                next_sq.push(make_pair(x, y));
            }
        }
        sq = next_sq;
    }
    return;
}

int main() {
    bool flag = false;
    scanf("%d %d\n", &r, &c);

    for (int i = 0; i < r; i += 1) {
        for (int j = 0; j < c; j += 1) {
            map[i][j] = getchar();
            if (map[i][j] == 'L') {
                if (!flag) {
                    melt[i][j] = true; flag = true;
                    sq.push(make_pair(i, j));
                }
                else {
                    end_x = i, end_y = j; 
                }
            }
        }
        getchar();
    }

    for (int i = 0; i < r; i += 1) {
        for (int j = 0; j < c; j += 1) {
            if (map[i][j] != 'X') {
                for (int k = 0; k < 4; k += 1) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < r && y >= 0 && y < c) {
                        if (map[x][y] == 'X') {
                            q.push(make_pair(i, j)); break;
                        }
                    }
                }
            }
        }
    }


    find();
    printf("%d\n", day);

    return 0;
}