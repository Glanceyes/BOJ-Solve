#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 50
#define MAX_H 1000000

int n, k_num, k_cnt;
int tmin, tmax, ans;
int min_height, max_height;
int start_x, start_y;
char map[MAX_N][MAX_N];
int height[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];

vector<int> tired;
vector<int>::iterator left, right;

int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

/* DFS로 */
void go(int x, int y) {
    if (height[x][y] < min_height || height[x][y] > max_height) return;
    if (visit[x][y]) return;
    visit[x][y] = true;
    if (height[x][y] < tmin) tmin = height[x][y];
    if (height[x][y] > tmax) tmax = height[x][y];
    if (map[x][y] == 'K') {
        k_cnt += 1;
        if (k_cnt == k_num) return;
    }
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!(nx >= 0 && nx < n && ny >= 0 && ny < n)) continue;
        go(nx, ny);
    }
}


int main() {
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = getchar();
            if (map[i][j] == 'P') {
                start_x = i; start_y = j;
            }
            if (map[i][j] == 'K') {
                k_num += 1;
            }
        }
        getchar();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &height[i][j]);
            tired.push_back(height[i][j]);
        }
    }

    ans = MAX_H;

    /* 벡터 원소 중복 제거 */
    sort(tired.begin(), tired.end());
    tired.erase(unique(tired.begin(), tired.end()), tired.end());

    left = tired.begin();
    right = tired.begin();

    while (right != tired.end() && left != tired.end()) {
        memset(visit, false, sizeof(visit));
        min_height = *left; max_height = *right;
        k_cnt = 0; tmin = tmax = height[start_x][start_y];

        go(start_x, start_y);

        if (k_cnt == k_num) {
            if (tmax - tmin < ans) ans = tmax - tmin;
            left++;
        }
        else if (k_cnt < k_num) right++;
    }
    printf("%d\n", ans);
   

    return 0;
}