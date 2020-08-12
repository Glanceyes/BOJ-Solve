#include <cstdio>
#include <iostream>
using namespace std;

#define S_MAX 50

int len;
char s[S_MAX + 2];
char a[S_MAX + 2];
bool d[S_MAX + 1][2][3][S_MAX + 2][S_MAX + 2][S_MAX + 2];

bool find(int idx, int b, int c, int na, int nb, int nc) {
    if (idx == len) {
        return true;
    }

    if (d[idx][b][c][na][nb][nc]) {
        return false;
    }

    d[idx][b][c][na][nb][nc] = true;

    int tempb, tempc;
    tempb = (b > 0) ? (b - 1) : b;
    tempc = (c > 0) ? (c - 1) : c;

    if (na > 0) {
        a[idx] = 'A';
        if (find(idx + 1, tempb, tempc, na - 1, nb, nc)) {
            return true;
        }
    }
    if (nb > 0 && !b) {
        a[idx] = 'B';
        if (find(idx + 1, 1, tempc, na, nb - 1, nc)) {
            return true;
        }
    }
    if (nc > 0 && !c) {
        a[idx] = 'C';
        if (find(idx + 1, tempb, 2, na, nb, nc - 1)) {
            return true;
        }
    }

    return false;
}

int main() {
    int na, nb, nc;
    cin >> s;
    
    int temp = 0;
    na = nb = nc = 0;
    while (s[temp] != '\0') {
        switch (s[temp]) {
        case 'A': na += 1;
            break;
        case 'B': nb += 1;
            break;
        case 'C': nc += 1;
            break;
        }
        len += 1; temp += 1;
    }

    if (find(0, 0, 0, na, nb, nc)) {
        printf("%s\n", a);
    }
    else {
        printf("-1\n");
    }

    return 0;
}