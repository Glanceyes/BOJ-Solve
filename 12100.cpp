#include <cstdio>

using namespace std;

#define MAX 20

int n, maxvalue;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int find(int counter, int prvbd[MAX][MAX], int direction) {
    if (counter >= 5) {
        //printf("------------------------------\n");
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (maxvalue < prvbd[i][j]) maxvalue = prvbd[i][j];
        //        printf("%d ", prvbd[i][j]);
            }
        //    printf("\n");
        }
        return 0;
    }

    int tmpbd[MAX][MAX];
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            tmpbd[i][j] = prvbd[i][j];
        }
    }
    switch (direction) {
    case 1: // 위 방향
        for (int j = 0; j < n; j += 1) {
            int saveidx = -1;
            for (int i = 0; i < n; i += 1) {
                if (!tmpbd[i][j] && saveidx == -1) saveidx = i;
                else if (tmpbd[i][j] && saveidx != -1) {
                    int tempidx = i - 1;
                    while (tempidx >= saveidx) {
                        tmpbd[tempidx][j] = tmpbd[tempidx + 1][j];
                        tmpbd[tempidx + 1][j] = 0;
                        tempidx -= 1;
                    }
                    saveidx = tempidx + 2;
                }
            }
        }
        
        for (int i = 0; i < n - 1; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (tmpbd[i][j] == tmpbd[i + 1][j]) {
                    tmpbd[i][j] *= 2;
                    int temp = i + 1;
                    while (temp < n - 1) {
                        tmpbd[temp][j] = tmpbd[temp + 1][j];
                        temp += 1;
                    }
                    tmpbd[temp][j] = 0;
                }
            }
        }
        
        break;
    case 2:
        // 아래 방향
        for (int j = 0; j < n; j += 1) {
            int saveidx = -1;
            for (int i = n - 1; i >= 0; i -= 1) {
                if (!tmpbd[i][j] && saveidx == -1) saveidx = i;
                else if (tmpbd[i][j] && saveidx != -1) {
                    int tempidx = i + 1;
                    while (tempidx <= saveidx) {
                        tmpbd[tempidx][j] = tmpbd[tempidx - 1][j];
                        tmpbd[tempidx - 1][j] = 0;
                        tempidx += 1;
                    }
                    saveidx = tempidx - 2;
                }
            }
        }
        
        for (int i = n - 1; i > 0; i -= 1) {
            for (int j = 0; j < n; j += 1) {
                if (tmpbd[i][j] == tmpbd[i - 1][j]) {
                    tmpbd[i][j] *= 2;
                    int temp = i - 1;
                    while (temp > 0) {
                        tmpbd[temp][j] = tmpbd[temp - 1][j];
                        temp -= 1;
                    }
                    tmpbd[temp][j] = 0;
                }
            }
        }
        
        break;
    case 3:
        // 왼쪽 방향
        for (int i = 0; i < n; i += 1) {
            int saveidx = -1;
            for (int j = 0; j < n; j += 1) {
                if (!tmpbd[i][j] && saveidx == -1) saveidx = j;
                else if (tmpbd[i][j] && saveidx != -1) {
                    int tempidx = j - 1;
                    while (tempidx >= saveidx) {
                        tmpbd[i][tempidx] = tmpbd[i][tempidx + 1];
                        tmpbd[i][tempidx + 1] = 0;
                        tempidx -= 1;
                    }
                    saveidx = tempidx + 2;
                }
            }
        }
        
        for (int j = 0; j < n - 1; j += 1) {
            for (int i = 0; i < n; i += 1) {
                if (tmpbd[i][j] == tmpbd[i][j + 1]) {
                    tmpbd[i][j] *= 2;
                    int temp = j + 1;
                    while (temp < n - 1) {
                        tmpbd[i][temp] = tmpbd[i][temp + 1];
                        temp += 1;
                    }
                    tmpbd[i][temp] = 0;
                }
            }
        } 
        
        break;
    case 4:
        // 오른쪽 방향
        for (int i = 0; i < n; i += 1) {
            int saveidx = -1;
            for (int j = n - 1; j >= 0; j -= 1) {
                if (!tmpbd[i][j] && saveidx == -1) saveidx = j;
                else if (tmpbd[i][j] && saveidx != -1) {
                    int tempidx = j + 1;
                    while (tempidx <= saveidx) {
                        tmpbd[i][tempidx] = tmpbd[i][tempidx - 1];
                        tmpbd[i][tempidx - 1] = 0;
                        tempidx += 1;
                    }
                    saveidx = tempidx - 2;
                }
            }
        }
        
        for (int j = n - 1; j > 0; j -= 1) {
            for (int i = 0; i < n; i += 1) {
                if (tmpbd[i][j] == tmpbd[i][j - 1]) {
                    tmpbd[i][j] *= 2;
                    int temp = j - 1;
                    while (temp > 0) {
                        tmpbd[i][temp] = tmpbd[i][temp - 1];
                        temp -= 1;
                    }
                    tmpbd[i][temp] = 0;
                }
            }
        } 
        
        break;
    }

    for (int i = 1; i <= 4; i += 1) {
        find(counter + 1, tmpbd, i);
    }

    return 0;
}

int main() {
    int board[MAX][MAX];
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            scanf("%d", &board[i][j]);
        }
    }
    for (int i = 1; i <= 4; i += 1) {
        int tmpbd[MAX][MAX];
        for (int j = 0; j < n; j += 1) {
            for (int k = 0; k < n; k += 1) {
                tmpbd[j][k] = board[j][k];
            }
        }
        find(0, tmpbd, i);
    }
    printf("%d\n", maxvalue);

    return 0;
}