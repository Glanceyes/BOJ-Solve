#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

typedef struct BRIDGE {
    int vertex;
    int weight;
}Bridge;

int n, m, f1, f2, ans;
bool cross[10001];
vector<Bridge> v[10001];

bool go(int w) {
    memset(cross, false, sizeof(cross));
    queue<int> q;
    cross[f1] = true; q.push(f1);

    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == f2) {
            return true;
        }
        for (int i = 0; i < (int)v[x].size(); i += 1) {
            if (v[x][i].weight >= w) {
                if (!cross[v[x][i].vertex]) {
                    q.push(v[x][i].vertex);
                    cross[v[x][i].vertex] = true;
                }
            }
        }
    }
    
    return false;
}

void find(int left, int right) {
    if (left > right) return;
    int mid = left + (right - left) / 2;

    if (go(mid)) {
        ans = mid;
        find(mid + 1, right);
    }
    else {
        find(left, mid - 1);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i += 1) {
        int idx1, idx2, wgh;
        scanf("%d %d %d", &idx1, &idx2, &wgh);
        
        Bridge b1, b2;
        b1.vertex = idx2; b2.vertex = idx1;
        b1.weight = b2.weight = wgh;

        v[idx1].push_back(b1);
        v[idx2].push_back(b2);
    }
    scanf("%d %d", &f1, &f2);

    find(1, 1000000000);
    printf("%d\n", ans);

    return 0;
}