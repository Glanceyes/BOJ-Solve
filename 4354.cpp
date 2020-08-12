#include <iostream>
#include <string>
#include <vector>
using namespace std;

int kmp_pattern(string p) {
    int p_size = (int)p.size();
    vector<int> fail(p_size, 0);
    for (int i = 1, j = 0; i < p_size; i += 1) {
        while (j > 0 && p[i] != p[j]) {
            j = fail[j - 1];
        }
        if (p[i] == p[j]) {
            fail[i] = j + 1; j += 1;
        }
    }
    return fail[p_size - 1];
}

int main() {
    while (1) {
        string s;
        cin >> s;
        if (!s.compare(".")) {
            break;
        }
        int temp = kmp_pattern(s);
        int s_size = (int)s.size();
        if (s_size == 1 || s_size % (s_size - temp)) {
            printf("1\n");
        }
        else {
            printf("%d\n", s_size / (s_size - temp));
        }
    }

    return 0;
}