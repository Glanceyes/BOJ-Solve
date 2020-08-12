#include <cstdio>
#include <vector>
using namespace std;

int map[51][51];
int n, m, answer, house_num, chicken_num;
vector<pair<int, int>> house, chicken, choose;

int abs(int v1, int v2) {
    if (v1 > v2) {
        return (v1 - v2);
    }
    return (v2 - v1);
}

int find(pair<int, int> d1, pair<int, int> d2) {
    int result = abs(d1.first, d2.first);
    result += abs(d1.second, d2.second);
    return result;
}

void find(int idx, int start) {
    if (idx == m) {
        int result = 0;
        for (int i = 0; i < house_num; i += 1) {
            int chicken_distance = -1;
            for (int j = 0; j < m; j += 1) {
                int temp = find(house[i], choose[j]);
                if (chicken_distance == -1 || chicken_distance > temp) {
                    chicken_distance = temp;
                }
            }
            result += chicken_distance;
        }

        if (answer == -1 || answer > result) {
            answer = result;
        }
        return;
    }
    for (int i = start; i < chicken_num; i += 1) {
        choose.push_back(chicken[i]);
        find(idx + 1, i + 1);
        choose.pop_back();
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            scanf("%d", &map[i][j]);
            switch (map[i][j]) {
            case 1:
                house.push_back(make_pair(i, j));
                break;
            case 2:
                chicken.push_back(make_pair(i, j));
                break;
            default: break;
            }
        }
    }

    house_num = (int)house.size();
    chicken_num = (int)chicken.size();

    answer = -1; find(0, 0);
    printf("%d\n", answer);

    return 0;
}