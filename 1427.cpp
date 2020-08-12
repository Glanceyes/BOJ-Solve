#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    char c;
    while ((c = getchar()) != '\n') {
        v.push_back((int)(c - '0'));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); i += 1) {
        printf("%d", v[i]);
    }
    printf("\n");

    return 0;
}