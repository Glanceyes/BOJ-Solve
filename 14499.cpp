#include <cstdio>
#include <vector>
using namespace std;

int n, m, x, y, k;
int map[20][20];
int dice[7];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<int> mv;

int main() {
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < k; i += 1) {
        int command, temp; 
        scanf("%d", &command);
        switch (command) {
        case 1:
            if (y + dy[0] >= m) continue;
            temp = dice[3];
            dice[3] = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            if (!map[x][y + dy[0]]) {
                dice[6] = map[x][y + dy[0]] = temp;
            }
            else {
                dice[6] = map[x][y + dy[0]];
                map[x][y + dy[0]] = 0;
            }
            y += dy[0];
            break;
        case 2:
            if (y + dy[2] < 0) continue;
            temp = dice[4];
            dice[4] = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            if (!map[x][y + dy[2]]) {
                dice[6] = map[x][y + dy[2]] = temp;
            }
            else {
                dice[6] = map[x][y + dy[2]];
                map[x][y + dy[2]] = 0;
            }
            y += dy[2];
            break;
        case 3:
            if (x + dx[3] < 0) continue;
            temp = dice[2];
            dice[2] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            if (!map[x + dx[3]][y]) {
                dice[6] = map[x + dx[3]][y] = temp;
            }
            else {
                dice[6] = map[x + dx[3]][y];
                map[x + dx[3]][y] = 0;
            }
            x += dx[3];
            break;
        case 4:
            if (x + dx[1] >= n) continue;
            temp = dice[5];
            dice[5] = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            if (!map[x + dx[1]][y]) {
                dice[6] = map[x + dx[1]][y] = temp;
            }
            else {
                dice[6] = map[x + dx[1]][y];
                map[x + dx[1]][y] = 0;
            }
            x += dx[1];
            break;
        }
        
        mv.push_back(dice[1]);
    }

    for (unsigned int i = 0; i < mv.size(); i += 1) {
        printf("%d\n", mv[i]);
    }

    return 0;
}