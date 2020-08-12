#include <cstdio>
#include <vector>
#include <cstring>
#include <tuple>
using namespace std;

#define MAX 101

struct position {
    int x = 0, y = 0;
    position(int a, int b) {
        x = a; y = b;
    }
};

struct shark {
    int velocity = 0;
    int direction = 0;
    int size = 0;
    shark(int a, int b, int c) {
        velocity = a;
        direction = b;
        size = c;
    }
};

int r, c, m;
int fisher;
int present[MAX][MAX];
bool exist[10001];
vector<pair<position, shark>> sharks;

int go() {
    int result = 0;
    while (fisher <= c) {
        /* 낚시왕 오른쪽으로 한 칸 이동한다. */
        fisher += 1;
        if (fisher > c) break;
        /* 낚시왕 있는 열에 있는 상어 중에서 땅과 가장 가까운 상어 잡는다. */
        for (int row = 1; row <= r; row++) {
            if (present[row][fisher] != -1) {
                int idx = present[row][fisher];
                int size = sharks[idx].second.size;
                exist[idx] = false;
                present[row][fisher] = -1;
                result += size; break;
            }
        }
        /* 상어 이동한다 */
        memset(present, -1, sizeof(present));

        for (int i = 0; i < (int)sharks.size(); i++) {
            if (!exist[i]) continue;
            position pos = sharks[i].first;
            shark cur = sharks[i].second;
            int dir = 0;
            switch (cur.direction) {
            case 1: // 위쪽
            case 2: // 아래쪽
                dir = (cur.direction % 2) ? -1 : 1;
                for (int j = 0; j < cur.velocity % ((r - 1) * 2); j++) {
                    if (pos.x + dir <= 0 || pos.x + dir > r) {
                        dir *= -1; cur.direction += dir;
                    }
                    pos.x += dir;
                }
                break;
            case 3: // 오른쪽
            case 4: // 왼쪽
                dir = (cur.direction % 2) ? 1 : -1;
                for (int j = 0; j < cur.velocity % ((c - 1) * 2); j++) {
                    if (pos.y + dir <= 0 || pos.y + dir > c) {
                        dir *= -1; cur.direction -= dir;
                    }
                    pos.y += dir;
                }
                break;
            }
            /* 상어 이동 후에 다른 상어가 있는 경우*/
            if (present[pos.x][pos.y] != -1) {
                int idx = present[pos.x][pos.y];
                if (sharks[idx].second.size < cur.size) {
                    exist[idx] = false;
                }
                else {
                    exist[i] = false; continue;
                }
            }
            present[pos.x][pos.y] = i;
            sharks[i].first = pos;
            sharks[i].second = cur;
        }
    }
    return result;
}

int main() {
    scanf("%d %d %d", &r, &c, &m);
    memset(present, -1, sizeof(present));
    memset(exist, true, sizeof(exist));
    for (int i = 0; i < m; i++) {
        int x, y, s, d, z;
        scanf("%d %d %d %d %d", &x, &y, &s, &d, &z);
        sharks.push_back({ position(x, y), shark(s, d, z) });
        present[x][y] = i;
    }
    printf("%d\n", go());
    return 0;
}