#include <cstdio>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

int n, answer = -1;
int start_x, start_y;
int end_x, end_y;
char map[50][50];

int visit[50][50][3];
bool revisit[50][50];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int find() {
    queue<tuple<int, int, int, int>> q;
    for (int i = 0; i < 4; i += 1) {
        q.push(make_tuple(start_x, start_y, 0, i));
    }

    while (!q.empty()) {
        queue<tuple<int, int, int, int>> next_q;
        while (!q.empty()) {
            int x, y, tx, ty, num, tnum, dir, tdir;
            tie(x, y, num, dir) = q.front(); q.pop();

            tx = x + dx[dir]; ty = y + dy[dir];
            while (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                if (tx == end_x && ty == end_y) {
                    if (answer == -1 || answer > num) {
                        answer = num;
                    }
                }
                if (map[tx][ty] == '!') {
                    for (int i = 0; i < 3; i += 1) {
                        if (i == 0) {
                            tdir = dir; tnum = num;
                        }
                        else {
                            if (visit[tx][ty][i] == -1 ||
                                visit[tx][ty][i] > num + 1) {
                                tnum = visit[tx][ty][i] = num + 1;
                            }
                            else if (visit[tx][ty][i]) {
                                tnum = num;
                                if (!revisit[tx][ty]) {
                                    revisit[tx][ty] = true;
                                }
                                else {
                                    continue;
                                }
                            }
                            if (i == 1) {
                                if (dir % 2 == 0) {
                                    tdir = dir + 1;
                                }
                                else {
                                    tdir = dir - 1;
                                }
                            }
                            if (i == 2) {
                                switch (dir) {
                                case 0: tdir = 3; break;
                                case 1: tdir = 2; break;
                                case 2: tdir = 1; break;
                                case 3: tdir = 0; break;
                                }
                            }
                        }
                        next_q.push(make_tuple(tx, ty, tnum, tdir));
                    }
                }
                else if (map[tx][ty] != '.') {
                    break;
                }
                tx += dx[dir]; ty += dy[dir];
            }
        }
        q = next_q;
    }
    return 0;
}

int main() {
    bool flag = false;
    scanf("%d\n", &n);

    memset(visit, -1, sizeof(visit));

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            map[i][j] = getchar();
            if (map[i][j] == '#'){
                if (!flag) {
                    start_x = i; start_y = j; flag = true;
                }
                else {
                    end_x = i; end_y = j;
                }
            }
        }
        getchar();
    }
    find();
    printf("%d\n", answer);

    return 0;
}