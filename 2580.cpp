#include <cstdio>
#include <vector>

using namespace std;

int fillnum;
int sudo[9][9];
bool finishflag;
bool check1[9][10]; // 가로
bool check2[9][10]; // 세로
bool check3[3][3][10]; // 3 X 3 정사각형
vector<pair<pair<int, int>, int>> fillblank; // 앞에는 좌표, 뒤에는 값

void fill(int idx) {
    if (idx == fillnum) {
        for (int i = 0; i < fillnum; i += 1) {
            int tempx = fillblank[i].first.first;
            int tempy = fillblank[i].first.second;
            int tempvalue = fillblank[i].second;
            sudo[tempx][tempy] = tempvalue;
        }
        finishflag = true;
        return;
    }
    int temp1 = fillblank[idx].first.first;
    int temp2 = fillblank[idx].first.second;
    for (int i = 1; i < 10; i += 1) {
        if (!check1[temp1][i] && !check2[temp2][i] &&
            !check3[temp1 / 3][temp2 / 3][i]) {
            fillblank[idx].second = i;
            check1[temp1][i] = check2[temp2][i] = true;
            check3[temp1 / 3][temp2 / 3][i] = true;
            fill(idx + 1);
            if (finishflag) {
                return;
            }
            fillblank[idx].second = 0;
            check1[temp1][i] = check2[temp2][i] = false;
            check3[temp1 / 3][temp2 / 3][i] = false;
        }
    }
}

int main() {
    for (int i = 0; i < 9; i += 1) {
        for (int j = 0; j < 9; j += 1) {
            scanf("%d", &sudo[i][j]);
            if (!sudo[i][j]) {
                fillblank.push_back(make_pair(make_pair(i, j), 0));
                fillnum += 1;
            }
            else {
                check1[i][sudo[i][j]] = true;
                check2[j][sudo[i][j]] = true;
                check3[i / 3][j / 3][sudo[i][j]] = true;
            }
        }
    }

    fill(0);

    for (int i = 0; i < 9; i += 1) {
        for (int j = 0; j < 9; j += 1) {
            printf("%d ", sudo[i][j]);
        }
        printf("\n");
    }
    return 0;
}