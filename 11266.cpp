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
            // �ڽ� ��尡 �ڽ��� ��ġ�� �ʰ� �ڽ��� ���� ��带 ������ ���ϴ� ���
            if (!isRoot && low >= discovered[vertex]) {
                if (!isAP[vertex]) {
                    isAP[vertex] = true; cntAP += 1;
                }
            }
            dfsSeq = MIN(dfsSeq, low);
        }
        else {
            // ����� back edge�� ���ؼ� �̹� �湮�� ���� ���� ����Ǵ� ���
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