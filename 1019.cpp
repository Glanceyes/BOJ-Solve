#include <cstdio>
using namespace std;

int n, digit;
int d[11][10];

int decimal(int a) {
    if (a <= 0) return 0;
    int result = 1;
    while (a--) {
        result *= 10;
    }
    return result;
}

int main() {
    scanf("%d", &n);
    int tmp, left, prv, dec = 1;

    tmp = left = prv = n;

    while (tmp) {
        prv = tmp;
        tmp /= 10;
        digit += 1;
        dec *= 10;
    }
    dec /= 10; left %= dec;

    printf("prv: %d / left: %d / dec: %d / digit: %d\n", prv, left, dec, digit);

    if (dec > 1) {
        for (int i = 0; i < 10; i += 1) {
            d[1][i] = 1;
        }
        for (int i = 2; i <= digit; i += 1) {
            if (i < digit) {
                for (int j = 0; j < 10; j += 1) {
                    if (j) {
                        d[i][j] = d[i - 1][j] * 10 + decimal(i - 1);
                    }
                    else {
                        d[i][j] = (d[i - 1][j] + decimal(i - 2)) * 9 + d[i - 1][j];
                    }
                }
            }
            else {
                for (int j = 0; j < 10; j += 1) {
                    d[i][j] = d[i - 1][j] * prv;
                    if (j == 0) {
                        d[i][j] = d[i - 1][j] * prv + decimal(i - 2) * (prv - 1);
                    }
                    else if (j < prv) {
                        d[i][j] += decimal(i - 1);
                    }
                    else if (j == prv) {
                        d[i][j] += (left + 1);
                    }
                }
            }
        }
        dec /= 10; prv = left / dec; left %= dec;
        int tmpdigit = digit - 1, zeronum = 0;
        
        for (int i = 1; i <= digit; i += 1) {
            for (int j = 0; j < 10; j += 1) {
                printf("%d ", d[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        while (1) {
            if (prv) {
                d[digit][0] += zeronum * (left + 1);
                for (int i = 1; i < 10; i += 1) {
                    d[digit][i] += d[tmpdigit][i] * prv;
                    if (i < prv) {
                        d[digit][i] += decimal(tmpdigit - 1);
                    }
                    else if (i == prv) {
                        d[digit][i] += (left + 1);
                    }
                }
                zeronum = 0;
            }
            else {
                zeronum += 1;
            }
            printf("prv: %d / left: %d / dec: %d / tmpdigit: %d\n", prv, left, dec, tmpdigit);
            dec /= 10; if (dec < 10) break;
            prv = left / dec; left %= dec; tmpdigit -= 1;
        }
        prv = left;
        printf("prv: %d / left: %d / dec: %d / tmpdigit: %d\n", prv, left, dec, tmpdigit);
        if (prv) {
            d[digit][0] += zeronum * (prv + 1);
            for (int i = 1; i <= prv; i += 1) {
                d[digit][i] += 1;
            }
        }
        else {
            zeronum += 1;
            d[digit][0] += zeronum;
        }
    }

    for (int i = 1; i <= digit; i += 1) {
        for (int j = 0; j < 10; j += 1) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    return 0;
}