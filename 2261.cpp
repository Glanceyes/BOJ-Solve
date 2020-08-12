#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct POINT {
    int x, y;
}Point;

int n;

int distance(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool sort_x(const Point& a, const Point& b) {
    return (make_pair(a.x, a.y) < make_pair(b.x, b.y));
}

bool sort_y(const Point& a, const Point& b) {
    return (make_pair(a.y, a.x) < make_pair(b.y, b.x));
}

int find(vector<Point> &p, int start, int end) {
    int num = end - start + 1;
    if (num <= 3) {
        int result = -1;
        for (int i = start; i <= end - 1; i += 1) {
            for (int j = i + 1; j <= end; j += 1) {
                int temp = distance(p[i], p[j]);
                if (result == -1 || result > temp) {
                    result = temp;
                }
            }
        }
        return result;
    }
    int mid = start + (end - start) / 2;
    Point pivot = p[mid];
    
    int left = find(p, start, mid);
    int right = find(p, mid + 1, end);
    int result = (left < right) ? left : right;
    vector<Point> t; // 살펴볼 점들이 있는 최대 영역
    for (int i = start; i <= end; i += 1) {
        int d = p[i].x - p[mid].x;
        if (d * d < result) {
            t.push_back(p[i]);
        }
    }
    sort(t.begin(), t.end(), sort_y);
    for (int i = 0; i < (int)t.size() - 1; i += 1) {
        for (int j = i + 1; j < (int)t.size(); j += 1) {
            int d = t[j].y - t[i].y;
            if (d * d < result) {
                int c = distance(t[j], t[i]);
                if (c < result) {
                    result = c;
                }
            }
            else {
                break;
            }
        }
    }
    return result;
}

int main() {
    scanf("%d", &n);
    vector<Point> p;

    for (int i = 0; i < n; i += 1) {
        int ix, iy; scanf("%d %d", &ix, &iy);
        p.push_back({ ix, iy });
    }

    sort(p.begin(), p.end(), sort_x);

    printf("%d\n", find(p, 0, n - 1));

    return 0;
}