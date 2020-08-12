#include <cstdio>
#include <vector>
using namespace std;

#define MIN(a, b) (a < b) ? (a) : (b)

int v, e, cnt, cntAP;
bool isAP[10001];
int discovered[10001];

vector<int> edge[10001];

int findDfs(int vertex, bool isRoot) {
    discovered[vertex] = (cnt += 1);
    int dfsSeq = discovered[vertex];

    int childNum = 0;
    for (int i = 0; i < (int)edge[vertex].size(); i++) {
        int child = edge[vertex][i];
        if (!discovered[child]) {
            childNum += 1;
            int low = findDfs(child, false);
            // 자식 노드가 자신을 거치지 않고 자신의 위의 노드를 만나지 못하는 경우
            if (!isRoot && low >= discovered[vertex]) {
                if (!isAP[vertex]) {
                    isAP[vertex] = true; cntAP += 1;
                }
            }
            dfsSeq = MIN(dfsSeq, low);
        }
        else {
            // 노드의 back edge를 통해서 이미 방문한 조상 노드로 연결되는 경우
            dfsSeq = MIN(dfsSeq, discovered[child]);
        }
    }
    if (isRoot && childNum >= 2 && !isAP[vertex]) {
        isAP[vertex] = true; cntAP += 1;
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
            findDfs(i, true);
        }
    }

    printf("%d\n", cntAP);
    for (int i = 1; i <= v; i++) {
        if (isAP[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}