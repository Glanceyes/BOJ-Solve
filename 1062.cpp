#include <cstdio>
#include <vector>

using namespace std;

int n, k, maxcounter;
bool alphabet[26];
vector<char> words[50];

void find(int counter, int start) {
    if (counter == k - 5) {
        int tempcounter = 0;
        for (int i = 0; i < n; i += 1) {
            bool flag = true;
            for (unsigned int j = 0; j < words[i].size(); j += 1) {
                if (!alphabet[words[i][j] - 'a']) {
                    flag = false; break;
                }
            }
            if (flag) {
                tempcounter += 1;
            }
        }
        if (maxcounter < tempcounter) maxcounter = tempcounter;
        return;
    }
    for (int i = start; i < 26; i += 1) {
        if (!alphabet[i]) {
            alphabet[i] = true;
            find(counter + 1, i + 1);
            alphabet[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k); getchar();
    
    for (int i = 0; i < n; i += 1) {
        char c;
        while ((c = getchar()) != '\n') {
            words[i].push_back(c);
        }
    }

    if (k < 5) { 
        printf("0\n"); return 0; 
    }
    
    alphabet['a' - 'a'] = alphabet['c' - 'a'] = true;
    alphabet['i' - 'a'] = alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    
    find(0, 0);
    printf("%d\n", maxcounter);

    return 0;
}