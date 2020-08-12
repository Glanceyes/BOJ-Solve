#include <iostream>
#include <string>
using namespace std;

int fail[1000001];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    string s;
    cin >> s;
    
    fail[0] = 0;
    for (int i = 1, j = 0; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != s[j]) {
            j = fail[j - 1];
        }
        if (s[i] == s[j]) {
            fail[i] = j + 1; j += 1;
        }
        else {
            fail[i] = 0;
        }
    }

    for (int i = 0; i < (int)s.size(); i++) {
        /*
        if (!fail[i]) continue;
        int same = fail[i];
        int duple = same * 2 - (i + 1);
        int left = ((i + 1) - duple) / 2;
        if (left <= duple || !duple) {
            int left = ((i + 1) - duple) / 2;
            //printf("i: %d / same: %d / duple: %d / left: %d\n", i, same, duple, left);
            for (int j = left; j <= (i + 1); j += left) {
                int temp = (i + 1) - (j * 2);
                //printf("temp: %d\n", temp);
                if ((temp >= j && temp % j == 0) || !temp) {
                    printf("%d %d\n", i + 1, (i + 1) / j);
                    break;
                }
            }
        }
        */
        if (fail[i] && (i + 1) % (i + 1 - fail[i]) == 0) {
            printf("%d %d\n", (i + 1), (i + 1) / (i + 1 - fail[i]));
        }
    }

    return 0;
}