#include <cstdio>
#include <queue>
using namespace std;

#define r_max 250
#define c_max 250

int r, c, sn, wn;
char map[r_max][c_max];
int visit[r_max][c_max];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
pair<int, int> gp[r_max * c_max + 1];

void find(pair<int, int> p, int num) {
    queue<pair<int, int>> q;
    q.push(p); visit[p.first][p.second] = num;
    switch (map[p.first][p.second]) {
    case 'o': gp[num].first += 1;
        break;
    case 'v': gp[num].second += 1;
        break;
    }

    while (!q.empty()) {
        pair<int, int> np = q.front(); q.pop();
        
        for (int i = 0; i < 4; i += 1) {
            int nx = np.first + dx[i];
            int ny = np.second + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                if (!visit[nx][ny] && map[nx][ny] != '#') {
                    if (map[nx][ny] == 'o') {
                        gp[num].first += 1;
                    }
                    if (map[nx][ny] == 'v') {
                        gp[num].second += 1;
                    }
                    q.push(make_pair(nx, ny));
                    visit[nx][ny] = num;
                }
            }
        }
    }

    return;
}

int main() {
    int tn = 0;
    scanf("%d %d\n", &r, &c);
    for (int i = 0; i < r; i += 1) {
        for (int j = 0; j < c; j += 1) {
            map[i][j] = getchar();
        }
        getchar();
    }

    for (int i = 0; i < r; i += 1) {
        for (int j = 0; j < c; j += 1) {
            if (!visit[i][j] && map[i][j] != '#') {
                tn += 1; find(make_pair(i, j), tn);
            }
        }
    }

    for (int i = 1; i <= tn; i += 1) {
        if (gp[i].first > gp[i].second) {
            sn += gp[i].first;
        }
        else {
            wn += gp[i].second;
        }
    }

    printf("%d %d\n", sn, wn);

    return 0;
}