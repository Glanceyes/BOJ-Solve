#include <cstdio>
#include <queue>

using namespace std;

#define MAX 100

int t, h, w, result;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int steal[MAX + 2][MAX + 2];
bool key[26];
char map[MAX + 2][MAX + 2];

void compare(pair<int, int> prev, pair<int, int> nw, queue<pair<int, int>> &q, int add) {
    int x = prev.first; int y = prev.second;
    int nx = nw.first; int ny = nw.second;
    if (steal[x][y] + add > steal[nx][ny]) {
        steal[nx][ny] = steal[x][y] + add;
        q.push(make_pair(nx, ny));
    }
}

void find() {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    steal[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 평면도 범위 안에 들어오는지와 벽이 아닌지 확인
            if (nx >= 0 && nx < h + 2 &&
                ny >= 0 && ny < w + 2 && map[nx][ny] != '*') {
                // 알파벳 대문자인 문 처리
                if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') {
                    if (key[map[nx][ny] - 'A']) {
                        map[nx][ny] = '.';
                        compare(make_pair(x, y), make_pair(nx, ny), q, 0);
                    }
                    // 문 열 열쇠 없으면 다른 방향으로
                }
                // 열쇠 떨어져 있으면 챙기기
                if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z') {
                    key[map[nx][ny] - 'a'] = true;
                    map[nx][ny] = '.';
                    compare(make_pair(x, y), make_pair(nx, ny), q, 1);
                }
                // 빈 공간일 때
                if (map[nx][ny] == '.') {
                    compare(make_pair(x, y), make_pair(nx, ny), q, 0);
                }
                // 문서를 찾았을 때
                if (map[nx][ny] == '$') {
                    result += 1;
                    map[nx][ny] = '.';
                    compare(make_pair(x, y), make_pair(nx, ny), q, 0);
                }
            }
        }
    }
    return;
}

int main() {
    scanf("%d", &t);

    while (t--) {
        result = 0;
        scanf("%d %d\n", &h, &w);
        for (int i = 0; i < h + 2; i += 1) {
            for (int j = 0; j < w + 2; j += 1) {
                if (i == 0 || i == h + 1 ||
                    j == 0 || j == w + 1) {
                    map[i][j] = '.';
                }
                else {
                    map[i][j] = getchar();
                }
                steal[i][j] = -1;
            }
            if (i >= 1 && i <= h) {
                getchar();
            }
        }
        for (int i = 0; i < 26; i += 1) {
            key[i] = false;
        }
        char readKey;
        while ((readKey = getchar()) != '\n') {
            if (readKey == '0') {
                getchar(); break;
            }
            key[readKey - 'a'] = true;
        }

        find();

        printf("%d\n", result);
    }

    return 0;
}