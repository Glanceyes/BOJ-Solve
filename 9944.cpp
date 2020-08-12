#include <cstdio>
#include <iostream>
using namespace std;

#define n_max 30
#define m_max 30

int n, m, num, result;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
char map[n_max][m_max];
bool visit[n_max][m_max];

void go(int x, int y, int dir, int cnt, int mv) {
    visit[x][y] = true; cnt += 1;

    int nx, ny; bool flag = false;
    // ó�� ������ �� �� �������� �̵��� �Ұ��ϸ� 0 (���� ���� ����)
    if (cnt == 1){
    for (int i = 0; i < n; i += 1) {
        nx = x + dx[i]; ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!visit[nx][ny] && map[nx][ny] == '.') {
                flag = true; break;
            }
        }
    }

    if (!flag) {
        result = 0; return;
    }
    }

    // ��� �� ĭ�� �湮�ߴٸ�
    if (cnt == num) {
        if (result == -1 || result > mv) {
            result = mv;
        }
        visit[x][y] = false; return;
    }

    flag = false;
    nx = x + dx[dir], ny = y + dy[dir];

    // �̵��� ���� �������� ��� �̵� ��������
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (!visit[nx][ny] && map[nx][ny] == '.') {
            go(nx, ny, dir, cnt, mv); flag = true;
        }
    }

    // �ٸ� �������� �̵� �����ϸ�
    if (!flag) {
        for (int i = 0; i < 4; i += 1) {
            if (i == dir) continue;
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visit[nx][ny] && map[nx][ny] == '.') {
                    go(nx, ny, i, cnt, mv + 1);
                }
            }
        }
    }

    visit[x][y] = false;
    return;
}

int main() {
    int idx = 1;
    while (cin >> n >> m) {
        getchar();
        num = 0; result = -1;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if ((map[i][j] = getchar()) == '.') {
                    num += 1;
                }
            }
            getchar();
        }

        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (map[i][j] == '.') {
                    for (int k = 0; k < 4; k += 1) {
                        go(i, j, k, 0, 1);
                    }
                }
            }
        }
        printf("Case %d: %d\n", idx, result); idx += 1;
    }
    return 0;
}