#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int r, n, ans;
int m[100][100];
bool v[100][100];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool bfs(int m_min, int m_max) {
    if (!(m_min <= m[0][0] && m[0][0] <= m_max)) {
        return false;
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    v[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1 && y == n - 1) {
            while (!q.empty()) {
                q.pop();
            }
            return true;
        }

        for (int i = 0; i < 4; i += 1) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && 
                ny >= 0 && ny < n && !v[nx][ny]) {
                if (m_min <= m[nx][ny] && m[nx][ny] <= m_max) {
                    v[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    return false;
}

bool find(int mid) {
    for (int i = 0; i + mid <= 200; i += 1) {
        memset(v, false, sizeof(v));
        if (bfs(i, i + mid)) {
            return true;
        }
    }
    return false;
}

int main() {
        scanf("%d", &n);

        int left = 0, right = 0;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < n; j += 1) {
                scanf("%d", &m[i][j]);
                if (right < m[i][j]) {
                    right = m[i][j];
                }
            }
        }

        ans = 200;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (find(mid)) {
                if (mid < ans) {
                    ans = mid;
                }
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        printf("%d\n", ans);
    

    return 0;
}