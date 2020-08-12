#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using Point = pair<long long, long long>;
using Line = pair<Point, Point>;

int ccw(Point p1, Point p2, Point p3) {
    long long temp = 0;
    temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    temp -= p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;
    if (temp > 0) return 1;
    else if (temp < 0) return -1;
    else return 0;
}

bool cross(Line l1, Line l2) {
    int c1 = ccw(l1.first, l1.second, l2.first) * ccw(l1.first, l1.second, l2.second);
    int c2 = ccw(l2.first, l2.second, l1.first) * ccw(l2.first, l2.second, l1.second);
    return c1 < 0 && c2 < 0;
}

bool guard(Point& p1, int n, vector<Point>& barrier) {
    // 방어하고자 하는 좌표가 장벽 위에 있는지
    for (int i = 0; i < n; i += 1) {
        int temp = ccw(barrier[i], barrier[i + 1], p1);
        if (!temp) {
            auto minx = min(barrier[i].first, barrier[i + 1].first);
            auto maxx = max(barrier[i].first, barrier[i + 1].first);
            if (minx <= p1.first && p1.first <= maxx) {
                return 1;
            }
        }
    }
    int cnt = 0;
    Point pivot = { 1, 2147483647 };
    for (int i = 0; i < n; i += 1) {
        Line line = { pivot, p1 };
        cnt += cross(line, Line({ barrier[i], barrier[i + 1] }));
    }
    return (cnt % 2) ? true : false;
}

int main() {
    int n; scanf("%d", &n);
    vector<Point> barrier(n);
    for (int i = 0; i < n; i += 1) {
        scanf("%lld %lld", &barrier[i].first, &barrier[i].second);
    }
    barrier.push_back(barrier[0]);
    for (int i = 0; i < 3; i += 1) {
        Point p; scanf("%lld %lld", &p.first, &p.second);
        printf("%d\n", guard(p, n, barrier));
    }
}