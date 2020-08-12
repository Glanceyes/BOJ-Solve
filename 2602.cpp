#include <iostream>
#include <string>
using namespace std;

string step, bridge[2];
int method[101][2][21];

int main() {
    cin >> step;
    
    for (int i = 0; i < 2; i += 1) {
        cin >> bridge[i];
    }

    for (int i = 0; i < (int)bridge[0].length(); i += 1) {
        if (step[0] == bridge[0][i]) {
            method[i][0][1] = 1;
        }
        if (step[0] == bridge[1][i]) {
            method[i][1][1] = 1;
        }
    }

    for (int i = 1; i < (int)step.length(); i += 1) {
        for (int l = 0; l < 2; l += 1) {
            int idx_1, idx_2;
            if (!l) { idx_1 = 0; idx_2 = 1; }
            else { idx_1 = 1; idx_2 = 0; }
            for (int j = 0; j < (int)bridge[idx_1].length(); j += 1) {
                if (step[i] == bridge[idx_1][j]) {
                    for (int k = 0; k < j; k += 1) {
                        if (step[i - 1] == bridge[idx_2][k]) {
                            method[j][idx_1][i + 1] += method[k][idx_2][i];
                        }
                    }
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < (int)bridge[0].length(); i += 1) {
        for (int j = 0; j < 2; j += 1) {
            answer += method[i][j][step.length()];
        }
    }

    printf("%d\n", answer);
    return 0;
}