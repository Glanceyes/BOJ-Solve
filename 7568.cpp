#include <cstdio>
#include <vector>
using namespace std;

struct person {
    int weight;
    int height;
};

int n;

int main() {
    scanf("%d", &n);

    vector<person> people(n);
    vector<int> rank(n);

    for (int i = 0; i < n; i += 1) {
        scanf("%d %d", &people[i].weight, &people[i].height);
    }
    
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            if (i == j) continue;
            if (people[i].weight < people[j].weight &&
                people[i].height < people[j].height) {
                rank[i] += 1;
            }
        }
    }
    for (int i = 0; i < n; i += 1) {
        printf("%d ", rank[i] + 1);
    }
    printf("\n");

    return 0;
}