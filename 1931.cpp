#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Con_tm {
    int start;
    int end;
} con_tm;

int n, answer, finish;
vector<con_tm> con;

bool cmp(const con_tm& c1, const con_tm& c2) {
    if (c1.end < c2.end) {
        return true;
    }
    else if (c1.end == c2.end) {
        return c1.start < c2.start;
    }
    else {
        return false;
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        int in1, in2; con_tm input;
        scanf("%d %d", &in1, &in2);
        input.start = in1; input.end = in2;
        con.push_back(input);
    }

    stable_sort(con.begin(), con.end(), cmp);

    int idx = 0, temp_end = 0;
    finish = con[n - 1].end;

    while (idx < n) {
        if (temp_end <= con[idx].start && con[idx].end <= finish) {
            temp_end = con[idx].end; answer += 1;
        }
        idx += 1;
    }
    printf("%d\n", answer);

    return 0;
}