#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define MAX 20
#define DIRTYMAX 10

int w, h, counter;
int startX, startY, result;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int path[MAX][MAX][DIRTYMAX + 1];
int dist[DIRTYMAX + 1][DIRTYMAX + 1];
char map[MAX][MAX];
bool check[DIRTYMAX + 1];
vector<pair<int, int>> messy;
vector<pair<int, int>> sequence;

// 미리 더러운 방 사이의 거리를 구해 놓음
bool go(pair<int, int> start, int idx) {
    int clean = 0;
    int nx = start.first, ny = start.second;
    queue<pair<int, int>> q;
    q.push(make_pair(nx, ny));
    path[nx][ny][idx] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int num = path[x][y][idx];
        q.pop();

        for (int i = 0; i < 4; i += 1) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 
                && ny < w && map[nx][ny] != 'x') {
                if (path[nx][ny][idx] == -1) {
                    path[nx][ny][idx] = num + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    for (int i = 0; i < counter; i += 1) {
        int tmpx = messy[i].first;
        int tmpy = messy[i].second;
        if (path[tmpx][tmpy][idx] != -1) {
            dist[idx][i] = path[tmpx][tmpy][idx];
        }
        else {
            return false;
        }
    }

    return true;
}

void find(int idx, int prev, int sum) {
    if (idx >= counter) {
        if (result == -1 || result > (sum + dist[prev][counter])) {
            result = sum + dist[prev][counter];
        }
        return;
    }
    for (int i = 0; i < counter; i += 1) {
        if (!check[i]) {
            check[i] = true;
            sequence.push_back(make_pair(messy[i].first, messy[i].second));
            find(idx + 1, i, sum + dist[prev][i]);
            sequence.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    while (1) {
        messy.clear();
        bool flag = true;
        counter = 0; result = -1;
        scanf("%d %d", &w, &h);

        if (w == 0 && h == 0) { 
            break; 
        }
        getchar();
        for (int i = 0; i < h; i += 1) {
            for (int j = 0; j < w; j += 1) {
                map[i][j] = getchar();
                if (map[i][j] == 'o') {
                    startX = i; startY = j;
                }
                if (map[i][j] == '*') {
                    counter += 1;
                    messy.push_back(make_pair(i, j));
                }
                for (int k = 0; k < DIRTYMAX + 1; k += 1) {
                    path[i][j][k] = -1;
                }
            }
            getchar();
        }
        
        for (int i = 0; i < DIRTYMAX + 1; i += 1) {
            check[i] = false;
            for (int j = 0; j < DIRTYMAX + 1; j += 1) {
                dist[i][j] = 0;
            }
        }

        messy.push_back(make_pair(startX, startY));
        for (int i = 0; i <= counter; i += 1) {
            if (!go(make_pair(messy[i].first, messy[i].second), i)) {
                printf("-1\n"); flag = false; break;
            }
        }

        if (!flag) continue;

        find(0, counter, 0);
        printf("%d\n", result);
    }
    return 0;
}