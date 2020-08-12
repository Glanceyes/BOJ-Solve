#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using Edge = pair<int, int>;

#define MAX_NUM 100000
#define MIN(a, b) (a < b) ? (a) : (b)
#define MAX(a, b) (a >= b) ? (a) : (b)

int v, e, q, cnt, cntAP;
int lowlink[MAX_NUM + 1];
int counter[MAX_NUM + 1];
int discovered[MAX_NUM + 1];
bool cuttingPoint[MAX_NUM + 1];
vector<int> edge[MAX_NUM + 1];
vector<Edge> cuttingEdge;

int findDfs(int vertex, int parent, bool isRoot) {
    discovered[vertex] = (cnt += 1);
    counter[vertex] = cnt;
    printf("vertex: %d / cnt: %d\n", vertex, cnt);
    int dfsSeq = discovered[vertex];

    int childNum = 0;
    for (int i = 0; i < (int)edge[vertex].size(); i++) {
        int child = edge[vertex][i];

        if (!discovered[child]) {
            childNum += 1;
            int low = findDfs(child, vertex, false);
            if (low > discovered[vertex] && child != parent) {
                int minv = MIN(vertex, child);
                int maxv = MAX(vertex, child);
                cuttingEdge.push_back({ minv, maxv });
            }
            if (!isRoot && low >= discovered[vertex]) {
                if (!cuttingPoint[vertex]) {
                    cuttingPoint[vertex] = true; cntAP += 1;
                }
            }
            dfsSeq = MIN(dfsSeq, low);
        }
        else {
            dfsSeq = MIN(dfsSeq, discovered[child]);
        }
    }

    if (isRoot && childNum > 1) {
        if (!cuttingPoint[vertex]) {
            cuttingPoint[vertex] = true; cntAP += 1;
        }
    }
    return dfsSeq;
}

int main() {
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        int a, b; scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 1; i <= v; i++) {
        if (!discovered[i]) {
            findDfs(i, 0, true);
        }
    }

    printf("AP\n");
    for (int i = 1; i <= v; i++) {
        printf("[%d] %d\n", i, counter[discovered[i]]);
    }
    
    
    /*
    sort(cuttingEdge.begin(), cuttingEdge.end());
    int cutNum = (int)cuttingEdge.size();
    printf("%d\n", cutNum);
    for (int i = 0; i < cutNum; i++) {
        printf("%d %d\n", cuttingEdge[i].first, cuttingEdge[i].second);
    }
    */
    /*
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int type; scanf("%d", &type);
        switch (type) {
        case 1:
        case 2:
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            if (rootVertex[a] != rootVertex[b]) {
                printf("no\n");
            }
            else {
                printf("yes\n");
            }
            break;
        }
    }
    */

    return 0;
}