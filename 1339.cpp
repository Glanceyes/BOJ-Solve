#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

#define MAX 10

int n, alphabetnum;
long long maxresult = 0;
int alphabet[26];
bool num_check[10];
bool ab_check[26];
vector<pair<char, int>> ab;
vector<char> alpha[MAX];

void find(int idx) {
    if (idx == alphabetnum) {
        long long result = 0;
        for (int i = 0; i < n; i += 1) {
            long long tempnum = 0;
            for (unsigned int j = 0; j < alpha[i].size(); j += 1) {
                tempnum = (tempnum * 10) + alphabet[alpha[i][j] - 'A'];
            }
            result += tempnum;
        }
        if (maxresult < result) maxresult = result;
        return;
    }
    for (int i = 0; i <= 9; i += 1) {
        if (!num_check[i]) {
            num_check[i] = true;
            alphabet[ab[idx].first - 'A'] = ab[idx].second = i;
            find(idx + 1);
            alphabet[ab[idx].first - 'A'] = ab[idx].second = -1;
            num_check[i] = false;
        }
    }
}


int main() {
    scanf("%d", &n); getchar();

    for (int i = 0; i < n; i += 1) {
        char tmpc;
        while ((tmpc = getchar()) != '\n') {
            alpha[i].push_back(tmpc);
            if (!ab_check[tmpc - 'A']) {
                alphabetnum += 1;
                ab.push_back(make_pair(tmpc, -1));
                ab_check[tmpc - 'A'] = true;
            }
        }
    }

    memset(alphabet, -1, sizeof(alphabet));

    find(0);
    printf("%lld\n", maxresult);

    return 0;
}