#include <cstdio>
#include <queue>
using namespace std;

int n;
int d[5001];
int v[2]{ 3, 5 };

void find() {
    queue<int> q;
    q.push(0); d[0] = 0;

    while (!q.empty()) {
        int x = q.front(); q.pop();
        
        for (int i = 0; i < 2; i += 1) {
            int nx = x + v[i];
            if (nx <= 5000) {
                if (d[nx] == -1 || d[nx] > d[x] + 1) {
                    d[nx] = d[x] + 1;
                    q.push(nx);
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i <= 5000; i += 1) {
        d[i] = -1;
    }

    find();
    printf("%d\n", d[n]);

    return 0;
}