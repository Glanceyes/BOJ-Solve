#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define N_MAX 50001

int n, t;
int visit[N_MAX];
vector<pair<int, int>> furrow;

int abs_val(int x, int y) {
    if (x - y < 0) return y - x;
    return x - y;
}

int go() {
    queue<int> q; q.push(0); visit[0] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (furrow[x].second >= t) return visit[x];
        for (int i = x - 1; i >= 0; i--) {
            if (abs_val(furrow[x].first, furrow[i].first) > 2) break;
            if (abs_val(furrow[x].second, furrow[i].second) > 2) continue;
            if (visit[i] == -1 || visit[i] > visit[x] + 1) {
                visit[i] = visit[x] + 1; q.push(i);
            }
        }
        for (int i = x + 1; i <= n; i++) {
            if (abs_val(furrow[x].first, furrow[i].first) > 2) break;
            if (abs_val(furrow[x].second, furrow[i].second) > 2) continue;
            if (visit[i] == -1 || visit[i] > visit[x] + 1) {
                visit[i] = visit[x] + 1; q.push(i);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &t);
    furrow.push_back({ 0, 0 });
    for (int i = 0; i < n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        furrow.push_back({ x, y });
    }
    fill(visit, visit + (n + 1), -1);
    sort(furrow.begin(), furrow.end());
    printf("%d\n", go());

    return 0;
}