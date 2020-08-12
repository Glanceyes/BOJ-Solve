#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

#define n_max 20
#define m_max 20

int n, m;
int cx[2], cy[2];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
char map[n_max][m_max];
bool visit[n_max][m_max][n_max][m_max];

int go() {
    int counter = 0;
    queue<tuple<pair<int, int>, pair<int,int>>> q;
    q.push(make_tuple(make_pair(cx[0], cy[0]), make_pair(cx[1], cy[1])));
    visit[cx[0]][cy[0]][cx[1]][cx[2]] = true;

    while (counter < 10) {
        queue<tuple<pair<int, int>, pair<int, int>>> next_q;
        while (!q.empty()) {
            pair<int, int> t1, t2, n1, n2;
            tie(t1, t2) = q.front(); q.pop();
            
            for (int i = 0; i < 4; i += 1) {
                bool flag1 = false, flag2 = false;
                n1.first = t1.first + dx[i];
                n1.second = t1.second + dy[i];
                n2.first = t2.first + dx[i];
                n2.second = t2.second + dy[i];

                if (n1.first < 0 || n1.first >= n ||
                    n1.second < 0 || n1.second >= m){
                    flag1 = true;
                }
                if (n2.first < 0 || n2.first >= n ||
                    n2.second < 0 || n2.second >= m) {
                    flag2 = true;
                }

                if ((flag1 && !flag2) || (!flag1 && flag2)) {
                    while (!q.empty()) {
                        q.pop();
                    }
                    while (!next_q.empty()) {
                        next_q.pop();
                    }
                    return counter + 1;
                }
                else if (flag1 && flag2) {
                    continue;
                }

                if (map[n1.first][n1.second] == '#') {
                    n1.first = t1.first;
                    n1.second = t1.second;
                }
                if (map[n2.first][n2.second] == '#') {
                    n2.first = t2.first;
                    n2.second = t2.second;
                }

                if (!visit[n1.first][n1.second][n2.first][n2.second]) {
                    visit[n1.first][n1.second][n2.first][n2.second] = true;
                    next_q.push(make_tuple(n1, n2));
                }
            }
        }
        q = next_q;
        counter += 1;
    }

    return -1;
}

int main() {
    int cnt = 0;
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            map[i][j] = getchar();
            if (map[i][j] == 'o' && cnt < 2) {
                cx[cnt] = i; cy[cnt] = j;
                map[i][j] = '.'; cnt += 1;
            }
        }
        getchar();
    }

    printf("%d\n", go());

    return 0;
}