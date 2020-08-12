#include <cstdio>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

#define MAX_DISTANCE 99999

int n, m, fish, answer;
int shark_size = 2;
int shark_x, shark_y;
int water[20][20];
int visit[20][20];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void find() {
    queue<tuple<int, int>> q;
    q.push(make_tuple(shark_x, shark_y));
    visit[shark_x][shark_y] = 0;

    int eaten_fish = 0, move_x, move_y, min_distance;

    while (!q.empty()) {
        queue<tuple<int, int>> next_q;
        move_x = -1, move_y = -1, min_distance = MAX_DISTANCE;

        while (!q.empty()) {
            int x, y, distance;
            tie(x, y) = q.front(); q.pop();
            distance = visit[x][y];

            for (int i = 0; i < 4; i += 1) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (water[nx][ny] <= shark_size) {
                        if (!water[nx][ny] || water[nx][ny] == shark_size) {
                            if (visit[nx][ny] == -1 || visit[nx][ny] > distance + 1) {
                                visit[nx][ny] = distance + 1;
                                q.push(make_tuple(nx, ny));
                            }
                        }
                        else if (water[nx][ny] < shark_size) {
                            if (visit[nx][ny] == -1 || visit[nx][ny] > distance + 1) {
                                visit[nx][ny] = distance + 1;
                                if (move_x == -1 || min_distance > visit[nx][ny]) {
                                    move_x = nx; move_y = ny;
                                    min_distance = visit[nx][ny];
                                }
                                else if (min_distance == visit[nx][ny]) {
                                    if (move_x > nx || (move_x == nx && move_y > ny)) {
                                        move_x = nx; move_y = ny;
                                        min_distance = visit[nx][ny];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (move_x != -1) {
            answer += visit[move_x][move_y];
            fish -= 1; memset(visit, -1, sizeof(visit));
            water[move_x][move_y] = visit[move_x][move_y] = 0;
            next_q.push(make_tuple(move_x, move_y));
            eaten_fish += 1;
        }
        else {
            return;
        }

        q = next_q;

        if (eaten_fish == shark_size) {
            shark_size += 1; eaten_fish = 0;
        }

        if (!fish) {
            return;
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            scanf("%d", &water[i][j]);
            if (water[i][j]) {
                if (water[i][j] == 9) {
                    shark_x = i; shark_y = j;
                    water[i][j] = 0;
                }
                else {
                    fish += 1;
                }
            }
        }
    }

    memset(visit, -1, sizeof(visit));

    if (fish) {
        find();
    }
    printf("%d\n", answer);

    return 0;
}