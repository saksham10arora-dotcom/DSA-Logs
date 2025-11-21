/**
 * Problem: Closest Pair of Points (CSES 2194)
 * Link: https://cses.fi/problemset/task/2194
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

struct cmpY {
    bool operator()(const Point& a, const Point& b) const {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    }
};

// --- Optimal Solution (Sweep Line) ---
// Time Complexity: O(N log N)
// Space Complexity: O(N)
long long distSq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    // int n; cin >> n;
    // vector<Point> p(n);
    // for(int i=0; i<n; i++) cin >> p[i].x >> p[i].y;
    // sort(p.begin(), p.end());
    // set<Point, cmpY> s;
    // long long d = 8e18;
    // int j = 0;
    // for (int i = 0; i < n; i++) {
    //     long long dd = ceil(sqrt(d));
    //     while (p[i].x - p[j].x >= dd) {
    //         s.erase(p[j++]);
    //     }
    //     auto it1 = s.lower_bound({-1000000001, p[i].y - dd});
    //     auto it2 = s.upper_bound({1000000001, p[i].y + dd});
    //     for (auto it = it1; it != it2; it++) {
    //         d = min(d, distSq(p[i], *it));
    //     }
    //     s.insert(p[i]);
    // }
    // cout << d << endl;
    return 0;
}












