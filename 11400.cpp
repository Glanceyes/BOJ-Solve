#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using Edge = pair<int, int>;

#define MIN(a, b) (a < b) ? (a) : (b)
#define MAX(a, b) (a >= b) ? (a) : (b)

int v, e, cnt;
int discovered[100001];

vector<int> edge[100001];
vector<Edge> cuttingEdge;

int findDfs(int vertex, int parent) {
    discovered[vertex] = (cnt += 1);
    int dfsSeq = discovered[vertex];

    for (int i = 0; i < (int)edge[vertex].size(); i++) {
        int child = edge[vertex][i];

        if (child == parent) continue;
        if (!discovered[child]) {
            int low = findDfs(child, vertex);
            // 현재 노드와 부모 사이의 간선을 지나는지의 유무이므로 등호 제거
            if (low > discovered[vertex]) {
                int minv = MIN(vertex, child);
                int maxv = MAX(vertex, child);
                cuttingEdge.push_back({ minv, maxv });
            }
            dfsSeq = MIN(dfsSeq, low);
        }
        else {
            dfsSeq = MIN(dfsSeq, discovered[child]);
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
            findDfs(i, 0);
        }
    }

    sort(cuttingEdge.begin(), cuttingEdge.end());
    int cutNum = (int)cuttingEdge.size();
    printf("%d\n", cutNum);
    for (int i = 0; i < cutNum; i++) {
        printf("%d %d\n", cuttingEdge[i].first, cuttingEdge[i].second);
    }

    return 0;
}