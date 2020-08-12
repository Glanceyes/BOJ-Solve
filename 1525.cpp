#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define RESULT 123456780

int numValue(int* v) {
    int temp = 0;
    for (unsigned int i = 0; i < 9; i += 1) {
        temp = temp * 10 + v[i];
    }
    return temp;
}

int main() {
    int start[9];
    for (int i = 0; i < 9; i += 1) {
        scanf("%d", &start[i]);
    }
    map<int, int> m;
    m.insert(make_pair(numValue(start), 0));

    queue<int> q;
    q.push(numValue(start));
    while (!q.empty()) {
        int nv = q.front();
        int tmp[9]; q.pop();
        int pvt = 0;

        int tmpnv = nv;
        for (int i = 8; i >= 0; i -= 1) {
            if (!(tmpnv % 10)) {
                pvt = i;
            }
            tmp[i] = tmpnv % 10;
            tmpnv /= 10;
        }
        int temp = tmp[pvt], numKey;

        if (pvt - 3 >= 0) {
            tmp[pvt] = tmp[pvt - 3];
            tmp[pvt - 3] = temp;
            if (m.find((numKey = numValue(tmp))) == m.end()) {
                m.insert(make_pair(numKey, m[nv] + 1));
                q.push(numKey);
            }
            tmp[pvt - 3] = tmp[pvt];
            tmp[pvt] = temp;
        }
        if (pvt + 3 < 9) {
            tmp[pvt] = tmp[pvt + 3];
            tmp[pvt + 3] = temp;
            if (m.find((numKey = numValue(tmp))) == m.end()) {
                m.insert(make_pair(numKey, m[nv] + 1));
                q.push(numKey);
            }
            tmp[pvt + 3] = tmp[pvt];
            tmp[pvt] = temp;
        }
        if (pvt % 3 != 0) {
            tmp[pvt] = tmp[pvt - 1];
            tmp[pvt - 1] = temp;
            if (m.find((numKey = numValue(tmp))) == m.end()) {
                m.insert(make_pair(numKey, m[nv] + 1));
                q.push(numKey);
            }
            tmp[pvt - 1] = tmp[pvt];
            tmp[pvt] = temp;
        }
        if (pvt % 3 != 2) {
            tmp[pvt] = tmp[pvt + 1];
            tmp[pvt + 1] = temp;
            if (m.find((numKey = numValue(tmp))) == m.end()) {
                m.insert(make_pair(numKey, m[nv] + 1));
                q.push(numKey);
            }
            tmp[pvt + 1] = tmp[pvt];
            tmp[pvt] = temp;
        }
    }

    if (m.find(RESULT) == m.end()) {
        printf("-1\n");
    }
    else {
        printf("%d\n", m[RESULT]);
    }

    return 0;
}