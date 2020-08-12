#include <cstdio>
#include <queue>

using namespace std;

#define MAX 10

int n, m;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
char board[MAX][MAX];
bool check[MAX][MAX][MAX][MAX];

int bfs(int rx, int ry, int bx, int by, int counter) {
    queue<pair<int, int>> rq;
    queue<pair<int, int>> bq;

    rq.push(make_pair(rx, ry));
    bq.push(make_pair(bx, by));
    while (!rq.empty() && !bq.empty()) {
        queue<pair<int, int>> next_rq;
        queue<pair<int, int>> next_bq;
        //if (counter >= 10) break;
        while (!rq.empty() && !bq.empty()) {
            int nrx = rq.front().first, nry = rq.front().second;
            int nbx = bq.front().first, nby = bq.front().second;
            check[nrx][nry][nbx][nby] = true;
            rq.pop(); bq.pop();

            for (int i = 0; i < 4; i += 1) {
                int tmprx = nrx, tmpry = nry;
                int tmpbx = nbx, tmpby = nby;
                bool bflag1 = false; // �Ķ��� ���� �������� ���°�
                bool bflag2 = false; // �̵��ϴ� ���⿡ �������� �ִ°�

                while (tmpbx + dx[i] > 0 && tmpbx + dx[i] < n - 1 &&
                    tmpby + dy[i] > 0 && tmpby + dy[i] < m - 1) {
                    // �Ķ��� ���� �������� ��
                    if (board[tmpbx + dx[i]][tmpby + dy[i]] == 'O') {
                        bflag1 = true; break;
                    }
                    // �Ķ��� ���� �̵� �������� ���� ����
                    if (board[tmpbx + dx[i]][tmpby + dy[i]] == '#') {
                        break;
                    }
                    // �Ķ��� �� �̵� ��ο� ������ �� ����
                    if (tmpbx + dx[i] == nrx && tmpby + dy[i] == nry) {
                        bflag2 = true;
                    }
                    tmpbx += dx[i]; tmpby += dy[i];
                }
                if (bflag1) {
                    continue;
                }
                if (bflag2) {
                    tmpbx -= dx[i]; tmpby -= dy[i];
                }
                while (tmprx + dx[i] > 0 &&
                    tmprx + dx[i] < n - 1 &&
                    tmpry + dy[i] > 0 &&
                    tmpry + dy[i] < m - 1) {
                    if (board[tmprx + dx[i]][tmpry + dy[i]] == 'O') {
                        return counter + 1;
                    }
                    if (board[tmprx + dx[i]][tmpry + dy[i]] == '#') {
                        break;
                    }
                    tmprx += dx[i]; tmpry += dy[i];
                }
                if (tmprx == tmpbx && tmpry == tmpby) {
                    tmprx -= dx[i]; tmpry -= dy[i];
                }

                if (!check[tmprx][tmpry][tmpbx][tmpby]) {
                    //check[tmprx][tmpry][tmpbx][tmpby] = true;
                    next_rq.push(make_pair(tmprx, tmpry));
                    next_bq.push(make_pair(tmpbx, tmpby));
                }
            }
        }
        counter += 1;
        rq = next_rq;
        bq = next_bq;
    }
    return 0;
}

int main() {
    int rx = 0, ry = 0, bx = 0, by = 0, result;
    scanf("%d %d", &n, &m); getchar();

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            board[i][j] = getchar();
            if (board[i][j] == 'R') {
                rx = i; ry = j;
            }
            if (board[i][j] == 'B') {
                bx = i; by = j;
            }
        }
        getchar();
    }

    if ((result = bfs(rx, ry, bx, by, 0))) {
        printf("%d\n", result);
    }
    else {
        printf("-1\n");
    }

    return 0;
}