#include <cstdio>
#include <queue>
using namespace std;

#define f_max 1000000

int f, s, g, u, d;
int visit[f_max + 1];

int bfs() {
    queue<int> q;
    q.push(s);
    visit[s] = 0;

    while (!q.empty()) {
        int tf = q.front(); q.pop();
        if (tf == g) {
            while (!q.empty()) {
                q.pop();
            }
            return visit[tf];
        }

        if (tf + u <= f) {
            if (visit[tf + u] == -1 || 
                visit[tf + u] > visit[tf] + 1) {
                visit[tf + u] = visit[tf] + 1;
                q.push(tf + u);
            }
        }
        if (tf - d >= 1) {
            if (visit[tf - d] == -1 ||
                visit[tf - d] > visit[tf] + 1) {
                visit[tf - d] = visit[tf] + 1;
                q.push(tf - d);
            }
        }
    }

    return -1;
}

int main() {
    int result = 0;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    for (int i = 0; i <= f_max; i += 1) {
        visit[i] = -1;
    }

    if ((result = bfs()) != -1) {
        printf("%d\n", result);
    }
    else {
        printf("use the stairs\n");
    }

    return 0;
}