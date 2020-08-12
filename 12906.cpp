#include <cstdio>
#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>
#include <queue>
#include <array>
#include <string>
#include <map>
using namespace std;

typedef array<string, 3> strarr;

int num[3];
strarr s, d;
map<strarr, int> m;

int bfs() {
    queue<strarr> q;
    strarr a = { s[0], s[1], s[2] };
    q.push(a);
    m[a] = 0;

    while (!q.empty()) {
        strarr tmp = q.front();
        if (d == tmp) {
            while (!q.empty()) {
                q.pop();
            }
            return m[tmp];
        }

        strarr ts; q.pop();

        for (int i = 0; i < 3; i += 1) {
            for (int j = 0; j < 3; j += 1) {
                for (int k = 0; k < 3; k += 1) {
                    ts[k] = tmp[k];
                }
                if (i == j || ts[i].length() == 0) continue;
                char tmpc = ts[i].back();
                ts[i].pop_back();
                ts[j] += tmpc;

                if (m.find(ts) == m.end()) {
                    m[ts] = m[tmp] + 1;
                    q.push(ts);
                }
                else if (m[ts] > m[tmp] + 1) {
                    m[ts] = m[tmp] + 1;
                    q.push(ts);
                }
            }
        }
    }

    return 0;
}

int main() {
    for (int i = 0; i < 3; i += 1) {
        int len; scanf("%d", &len);
        if (!len) continue;

        getchar();
        for (int j = 0; j < len; j += 1) {
            char temp = getchar();
            num[temp - 'A'] += 1;
            s[i] += temp;
        }
        getchar();
    }

    for (int i = 0; i < 3; i += 1) {
        for (int j = 0; j < num[i]; j += 1) {
            d[i] += 'A' + i;
        }
    }

    printf("%d\n", bfs());

    return 0;
}