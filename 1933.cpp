#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX(x,y) (((x) > (y)) ? (x) : (y))

struct building {
    int l;
    int h;
    int r;
};

int n;
vector<building> v;

bool compare(building& a, building& b) {
    if (a.l < b.l) {
        return true;
    }
    else if (a.l == b.l) {
        if (a.h < b.h) {
            return true;
        }
        else if (a.h == b.h) {
            return a.r < b.r;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void append(vector<pair<int, int>>& result, pair<int, int> x) {
    int s = result.size();
    if (s > 0) {
        if (result[s - 1].second == x.second) {
            return;
        }
        if (result[s - 1].first == x.first) {
            result[s - 1].second = x.second;
            return;
        }
    }
    result.push_back(x);
}

vector<pair<int, int>> merge(vector<pair<int, int>>& left, vector<pair<int, int>>& right) {
    vector<pair<int, int>> result;
    int h1, h2, i, j; h1 = h2 = i = j = 0;
    while (i < (int)left.size() && j < (int)right.size()) {
        if (left[i].first < right[j].first) {
            h1 = left[i].second;
            append(result, make_pair(left[i].first, MAX(h1, h2)));
            i += 1;
        }
        else {
            h2 = right[j].second;
            append(result, make_pair(right[j].first, MAX(h1, h2)));
            j += 1;
        }
    }
    while (i < (int)left.size()) {
        append(result, make_pair(left[i].first, left[i].second)); 
        i += 1;
    }
    while (j < (int)right.size()) {
        append(result, make_pair(right[j].first, right[j].second));
        j += 1;
    }
    return result;
}

vector<pair<int, int>> find(vector<building>& a, int start, int end) {
    if (start == end) {
        vector<pair<int, int>> result;
        result.push_back(make_pair(a[start].l, a[start].h));
        result.push_back(make_pair(a[start].r, 0));
        return result;
    }
    int mid = start + (end - start) / 2;
    auto left = find(a, start, mid);
    auto right = find(a, mid + 1, end);
    return merge(left, right);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        building input; 
        scanf("%d %d %d", &input.l, &input.h, &input.r);
        v.push_back(input);
    }

    sort(v.begin(), v.end(), compare);

    auto ans = find(v, 0, n - 1);
    for (auto& iter : ans) {
        printf("%d %d ", iter.first, iter.second);
    }
    printf("\n");

    return 0;
}