#include <iostream>
#include <map>
#include <string>
using namespace std;

int t, f;
map<string, string> Parent;
map<string, int> Rank;

string Find(string x) {
    if (x == Parent[x]) {
        return x;
    }
    else {
        return Parent[x] = Find(Parent[x]);
    }
}

int Union(string x, string y) {
    x = Find(x);
    y = Find(y);
    if (x.compare(y) == 0) {
        return Rank[x];
    }
    if (Rank[x] < Rank[y]) {
        Parent[x] = y;
        return Rank[y] = Rank[x] + Rank[y];
    }
    else {
        Parent[y] = x;
        return Rank[x] = Rank[x] + Rank[y];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> f;
        string student1, student2;
        for (int i = 0; i < f; i += 1) {
            cin >> student1 >> student2;
            if (Rank.find(student1) == Rank.end()) {
                Rank[student1] = 1;
                Parent[student1] = student1;
            }
            if (Rank.find(student2) == Rank.end()) {
                Rank[student2] = 1;
                Parent[student2] = student2;
            }
            printf("%d\n", Union(student1, student2));
        }
        Parent.clear(); Rank.clear();
    }

    return 0;
}