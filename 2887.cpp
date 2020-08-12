#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define N_MAX 100000

int n; long long ans;
int parent[N_MAX];
int rnk[N_MAX];

struct planet {
    int idx, x, y, z;
};

struct tunnel {
    int a, b, weight;
    bool operator<(tunnel const& x) {
        if (weight < x.weight) return true;
        return false;
    }
};

bool compare_x(planet& a, planet& b) {
    if (a.x < b.x) return true;
    return false;
}

bool compare_y(planet& a, planet& b) {
    if (a.y < b.y) return true;
    return false;
}

bool compare_z(planet& a, planet& b) {
    if (a.z < b.z) return true;
    return false;
}

int find(int x) {
    if (x == parent[x]) return x;
    return (parent[x] = find(parent[x]));
}

void swap(int& a, int& b) {
    int temp = a;
    a = b; b = temp;
}

void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) swap(x, y);
    parent[y] = x;
    if (rnk[x] == rnk[y]) {
        rnk[x] = rnk[y] + 1;
    }
}

int main() {
    scanf("%d", &n);
    vector<planet> planets(n);
    vector<tunnel> tunnels;

    for (int i = 0; i < n; i++) {
        int x, y, z; 
        scanf("%d %d %d", &x, &y, &z);
        planets[i] = { i, x, y, z };
        parent[i] = i;
    }

    sort(planets.begin(), planets.end(), compare_x);
    for (int i = 0; i < n - 1; i++) {
        tunnels.push_back({ planets[i].idx, planets[i + 1].idx, planets[i + 1].x - planets[i].x });
    }

    sort(planets.begin(), planets.end(), compare_y);
    for (int i = 0; i < n - 1; i++) {
        tunnels.push_back({ planets[i].idx, planets[i + 1].idx, planets[i + 1].y - planets[i].y });
    }

    sort(planets.begin(), planets.end(), compare_z);
    for (int i = 0; i < n - 1; i++) {
        tunnels.push_back({ planets[i].idx, planets[i + 1].idx, planets[i + 1].z - planets[i].z });
    }

    sort(tunnels.begin(), tunnels.end());
    for (auto iter : tunnels) {
        int u = iter.a;
        int v = iter.b;
        /* cycle 형성 안 하는 경우 */
        if (find(u) != find(v)) {
            merge(u, v);
            ans += (long long)iter.weight;
        }
    }
    printf("%lld\n", ans);

    return 0;
}