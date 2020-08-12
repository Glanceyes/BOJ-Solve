#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, paint;
int map[1000][1000];
int mov[1000][1000];
int done[1000][1000];
bool visit[1000][1000];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int count(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visit[x][y] = true;

    int cnt = 0;

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop(); cnt += 1;

        for (int i = 0; i < 4; i += 1) {
            int tx = nx + dx[i];
            int ty = ny + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m){
                if (map[tx][ty] == 0 && visit[tx][ty] == false) {
                    visit[tx][ty] = true;
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }
    return cnt;
}

void update(int x, int y, int value) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    done[x][y] = paint;

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        map[nx][ny] = value; q.pop();

        for (int i = 0; i < 4; i += 1) {
            int tx = nx + dx[i];
            int ty = ny + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                if (map[tx][ty] == 0 && done[tx][ty] == 0) {
                    done[tx][ty] = paint;
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }
}

int main() {
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            char c = getchar();
            map[i][j] = (int)(c - '0') * (-1);
        }
        getchar();
    }

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (map[i][j] == 0) {
                paint += 1;
                int value = count(i, j);
                update(i, j, value);
            }
        }
    }


    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (map[i][j] == -1) {
                mov[i][j] = 1;
                vector<int> temp;
                for (int k = 0; k < 4; k += 1) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m) {
                        if (map[x][y] != -1) {
                            auto iter = find(temp.begin(), temp.end(), done[x][y]);
                            if (!temp.size() || iter == temp.end()) {
                                mov[i][j] += map[x][y];
                                temp.push_back(done[x][y]);
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            printf("%d", mov[i][j] % 10);
        }
        printf("\n");
    }

    return 0;
}