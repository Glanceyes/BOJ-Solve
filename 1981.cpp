#include <cstdio>
using namespace std;

int n, ans;
int m[100][100];
int v[100][100];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool find(int x, int y, int m_max, int m_min, int c) {
    if (m_max - m_min < v[x][y]) {
        if (m_max < m[x][y]) {
            m_max = m[x][y];
        }
        if (m_min > m[x][y]) {
            m_min = m[x][y];
        }
        if (m_max - m_min <= c) {
            v[x][y] = (m_max - m_min);
            if (x == n - 1 && y == n - 1) {
                return true;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }

    for (int i = 0; i < 4; i += 1) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (find(nx, ny, m_max, m_min, c)) {
                return true;
            }
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
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < n; j += 1) {
                v[i][j] = 201;
            }
        }
        if (find(0, 0, m[0][0], m[0][0], mid)) {
            ans = mid; right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}