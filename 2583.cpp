#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k, num;
int map[100][100];
vector<int> rectangle_size;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void swap(int* x, int* y) {
    if (*x > * y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    return;
}

int find(int x, int y) {
    int area = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    map[x][y] = num;

    while (!q.empty()) {
        int nx = q.front().first, ny = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i += 1) {
            int tx = nx + dx[i], ty = ny + dy[i];
            if (tx >= 0 && tx < m && ty >= 0 && ty < n) {
                if (!map[tx][ty]) {
                    map[tx][ty] = num; area += 1;
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }
    return area;
}

int main() {
    scanf("%d %d %d", &m, &n, &k);

    while (k--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

        swap(&x1, &x2); swap(&y1, &y2);

        for (int i = x1; i < x2; i += 1) {
            for (int j = y1; j < y2; j += 1) {
                map[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < m; i += 1) {
        for (int j = 0; j < n; j += 1) {
            if (!map[i][j]) {
                num += 1;
                rectangle_size.push_back(find(i, j));
            }
        }
    }

    sort(rectangle_size.begin(), rectangle_size.end());

    printf("%d\n", num);
    for (unsigned int i = 0; i < rectangle_size.size(); i += 1) {
        printf("%d ", rectangle_size[i]);
    }
    printf("\n");

    return 0;
}