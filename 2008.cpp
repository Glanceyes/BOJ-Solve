#include <cstdio>
#include <tuple>
using namespace std;

#define n_max 100
#define m_max 500
#define large_num 50000000

int n, m, a, b, x, y;
int d[n_max + 1][m_max + 1];
//bool v[n_max + 1][m_max + 1];
pair<int, int> s[m_max + 1];

int find(int tn, int tm, int pn) {
    int temp = 0;
    //v[tn][tm] = true;

    printf("tn: %d / tm: %d / pn: %d\n", tn, tm, pn);

    if (tm == 0) {
        if (tn == a) {
            return 0;
        }
        else {
            return large_num;
        }
    }

    if (d[tn][tm] != -1) {
        return d[tn][tm];
    }

    if (s[tm].first == tn || s[tm].second == tn) {
        if (s[tm].first == tn - 1 && s[tm].second == tn) {
            temp = find(tn - 1, tm - 1, -1);
            if (d[tn][tm] == -1 || d[tn][tm] > temp) {
                d[tn][tm] = temp;
            }
            if (tn + 1 <= n && tn + 1 != pn) {
                printf("error -> tn: %d / tm: %d / pn: %d\n", tn, tm, pn);
                temp = find(tn + 1, tm, tn) + y;
                if (d[tn][tm] == -1 || d[tn][tm] > temp) {
                    d[tn][tm] = temp;
                }
            }
        }
        else {
            temp = find(tn + 1, tm - 1, -1);
            if (d[tn][tm] == -1 || d[tn][tm] > temp) {
                d[tn][tm] = temp;
            }
            if (tn - 1 >= 1 && tn - 1 != pn) {
                temp = find(tn - 1, tm, tn) + y;
                if (d[tn][tm] == -1 || d[tn][tm] > temp) {
                    d[tn][tm] = temp;
                }
            }
        }
        temp = find(tn, tm - 1, -1) + x;
        if (d[tn][tm] == -1 || d[tn][tm] > temp) {
            d[tn][tm] = temp;
        }
    }
    else {
        if (tn - 1 >= 1 && tn - 1 != pn) {
            temp = find(tn - 1, tm, tn) + y;
            if (d[tn][tm] == -1 || d[tn][tm] > temp) {
                d[tn][tm] = temp;
            }
        }
        if (tn + 1 <= n && tn + 1 != pn) {
            temp = find(tn + 1, tm, tn) + y;
            if (d[tn][tm] == -1 || d[tn][tm] > temp) {
                d[tn][tm] = temp;
            }
        }
        temp = find(tn, tm - 1, -1);
        if (d[tn][tm] == -1 || d[tn][tm] > temp) {
            d[tn][tm] = temp;
        }
    }
    printf("d[%d][%d]: %d\n", tn, tm, d[tn][tm]);

    return d[tn][tm];
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &a, &b, &x, &y);

    for (int i = 1; i <= m; i += 1) {
        scanf("%d", &s[i].first);
        s[i].second = s[i].first + 1;
    }

    for (int i = 0; i <= n; i += 1) {
        for (int j = 0; j <= m; j += 1) {
            d[i][j] = -1;
        }
    }

    /*
    for (int i = 0; i <= m; i += 1) {
        printf("s[%d] : %d / %d\n", i, s[i].first, s[i].second);
    }
    */

    printf("%d\n", find(b, m, -1));

    return 0;
}