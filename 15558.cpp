#include <cstdio>
#include <queue>

using namespace std;

#define MAX 100000

int n, k;
int line1[MAX + 1];
int line2[MAX + 1];
int visit1[MAX + 1];
int visit2[MAX + 1];

bool go() {
    queue<pair<int, bool>> q;
    q.push(make_pair(1, false));
    int counter = 1;
    visit1[1] = 0;
    while (!q.empty()) {
        queue <pair<int, bool>> next_q;
        while (!q.empty()) {
            int x = q.front().first;
            bool right = q.front().second; q.pop();

            if (x + 1 > n || x + k > n) {
                while (!q.empty()) {
                    q.pop();
                }
                while (!next_q.empty()) {
                    next_q.pop();
                }
                return true;
            }

            int* line = ((right) ? line2 : line1);
            int* cline = ((right) ? line1 : line2);
            int* visit = ((right) ? visit2 : visit1);
            int* cvisit = ((right) ? visit1 : visit2);

            if (x + 1 <= n) {
                if (line[x + 1] && (visit[x + 1] == -1 ||
                    visit[x + 1] > visit[x] + 1)) {
                    visit[x + 1] = visit[x] + 1;
                    next_q.push(make_pair(x + 1, right));
                }
            }

            if (x - 1 > counter) {
                if (line[x - 1] && (visit[x - 1] == -1 ||
                    visit[x - 1] > visit[x] + 1)) {
                    visit[x - 1] = visit[x] + 1;
                    next_q.push(make_pair(x - 1, right));
                }
            }

            if (x + k <= n) {
                if (cline[x + k] && (cvisit[x + k] == -1 ||
                    cvisit[x + k] > visit[x] + 1)) {
                    cvisit[x + k] = visit[x] + 1;
                    next_q.push(make_pair(x + k, !right));
                }
            }
        }
        counter += 1;
        q = next_q;
    }

    return false;
}

int main() {
    scanf("%d %d\n", &n, &k);

    for (int i = 1; i <= n; i += 1) {
        line1[i] = (int)(getchar() - '0');
        visit1[i] = -1;
    } getchar();

    for (int i = 1; i <= n; i += 1) {
        line2[i] = (int)(getchar() - '0');
        visit2[i] = -1;
    } getchar();
    
    if (go()) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }

    return 0;
}