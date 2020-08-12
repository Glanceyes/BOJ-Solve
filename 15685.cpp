#include <cstdio>
#include <vector>
using namespace std;

int n, x, y, d, g;
bool visit[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void find(vector<int> &dragon, int x, int y, int d, int g) {
    int cnt = 1;
    visit[y][x] = true; y += dy[d]; x += dx[d];
    visit[y][x] = true;
    d = (d - 2 >= 0) ? (d - 2) : (d + 2);
    dragon.push_back(d);

    while (cnt <= g) {
        visit[y][x] = true; 
        int d_size = (int)dragon.size();
        for (int i = d_size - 1; i >= 0; i -= 1) {
            int dir = ((dragon[i] - 1 >= 0) ? dragon[i] - 1 : 3);
            y += dy[dir]; x += dx[dir];
            visit[y][x] = true;
            dir = (dir - 2) >= 0 ? (dir - 2) : (dir + 2);
            dragon.push_back(dir);
        }
        cnt += 1;
    }

}

int main() {
    int ans = 0;
    scanf("%d", &n);
    
    while (n--) {
        scanf("%d %d %d %d", &x, &y, &d, &g);
        vector<int> dragon;
        find(dragon, x, y, d, g);
    }
    for (int i = 0; i < 100; i += 1) {
        for (int j = 0; j < 100; j += 1) {
            if (visit[i][j] && visit[i + 1][j] &&
                visit[i][j + 1] && visit[i + 1][j + 1]) {
                ans += 1;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}