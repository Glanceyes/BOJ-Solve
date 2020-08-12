#include <cstdio>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

int a, b, c;
map<tuple<int, int, int>, int> v;

int bfs() {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(a, b, c));
    v[make_tuple(a, b, c)] = true;
    while (!q.empty()) {
        queue<tuple<int, int, int>> nq;
        while (!q.empty()) {
            int n[3], t[3];
            tie(n[0], n[1], n[2]) = q.front(); q.pop();

            if (n[0] == n[1] && n[1] == n[2]) {
                while (!q.empty()) {
                    q.pop();
                }
                return 1;
            }

            for (int i = 0; i < 3; i += 1) {
                for (int j = 0; j < 3; j += 1) {
                    if (i == j || n[i] == n[j]) continue;
                    t[0] = n[0]; t[1] = n[1]; t[2] = n[2];
                    if (n[i] < n[j]) {
                        t[i] = n[i] + n[i];
                        t[j] = n[j] - n[i];
                        if (v.find(make_tuple(t[0], t[1], t[2])) == v.end()) {
                            v[make_tuple(t[0], t[1], t[2])] = true;
                            nq.push(make_tuple(t[0], t[1], t[2]));
                        }
                    }
                }
            }
        }
        q = nq;
    }
    return 0;
}

int main() {
    scanf("%d %d %d", &a, &b, &c);

    printf("%d\n", bfs());

    return 0;
}