#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX_VALUE 10000
#define MIN(a, b) (a < b) ? (a) : (b)

int v, e, cnt, idx = 0;

stack<int> s;
int paint[MAX_VALUE + 1];
int discovered[MAX_VALUE + 1];
vector<int> edge[MAX_VALUE + 1];
vector<vector<int>> stcc;

int find(int v) {
    discovered[v] = (cnt += 1);
    int ret = discovered[v];
    s.push(v);

    for (int i = 0; i < (int)edge[v].size(); i++) {
        int child = edge[v][i];
        if (!discovered[child]) {
            int low = find(child);
            ret = MIN(ret, low);
        }
        else if (!paint[child]) {
            ret = MIN(ret, discovered[child]);
        }
    }
    
    if (ret == discovered[v]) {
        vector<int> cc;
        if ((int)s.size()) {
            idx += 1;
            while (1) {
                int x = s.top(); s.pop();
                paint[x] = idx;
                cc.push_back(x);
                if (x == v) break;
            }
            sort(cc.begin(), cc.end());
            stcc.push_back(cc);
        }
    }
    return ret;
}

int main() {
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        int a, b; scanf("%d %d", &a, &b);
        edge[a].push_back(b);
    }

    for (int i = 1; i <= v; i++) {
        if (!discovered[i]) {
            find(i);
        }
    }

    sort(stcc.begin(), stcc.end());
    printf("%d\n", idx);
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < (int)stcc[i].size(); j++) {
            printf("%d ", stcc[i][j]);
        }
        printf("-1\n");
    }

    return 0;
}