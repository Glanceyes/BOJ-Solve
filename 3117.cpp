#include <cstdio>
#include <vector>
using namespace std;

#define K_MAX 100001
#define D_MAX 31

vector<int> student;

int n, k, m;
int rec[K_MAX][D_MAX];

int main() {
    scanf("%d %d %d", &n, &k, &m);

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        student.push_back(x);
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d", &rec[i][0]);
    }

    for (int j = 1; j < D_MAX; j++) {
        for (int i = 1; i <= k; i++) {
            rec[i][j] = rec[rec[i][j - 1]][j - 1];
        }
    }

    for (auto x : student) {
        int t = m - 1;
        for (int i = 0; i < D_MAX; i++) {
            if (t % 2) x = rec[x][i];
            t /= 2;
        }
        printf("%d ", x);
    }

    return 0;
}