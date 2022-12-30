#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

using PDD = pair<double, double>;

const int N = 3005;
const double eps = 1e-12;
const double PI = acos(-1);

int n;
PDD q[N];
struct Circle {
    PDD p;
    double r;
};

int sign(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

int dcmp(double x, double y) {
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}

PDD operator-(PDD a, PDD b) {
    return {a.x - b.x, a.y - b.y};
}

PDD operator+(PDD a, PDD b) {
    return {a.x + b.x, a.y + b.y};
}

PDD operator*(PDD a, double t) {
    return {a.x * t, a.y * t};
}

PDD operator/(PDD a, double t) {
    return {a.x / t, a.y / t};
}

double operator*(PDD a, PDD b) {
    return a.x * b.y - a.y * b.x;
}

PDD rotate(PDD a, double b) {
    return {a.x * cos(b) + a.y * sin(b), -a.x * sin(b) + a.y * cos(b)};
}

double get_dist(PDD a, PDD b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

PDD get_line_intersection(PDD p, PDD v, PDD q, PDD w) {
    auto u = p - q;
    double t = w * u / (v * w);
    return p + v * t;
}

pair<PDD, PDD> get_line(PDD a, PDD b) {
    return {(a + b) / 2, rotate(b - a, PI / 2)};
}

Circle get_circle(PDD a, PDD b, PDD c) {
    auto u = get_line(a, b), v = get_line(a, c);
    auto p = get_line_intersection(u.x, u.y, v.x, v.y);
    return {p, get_dist(p, a)};
}

class Solution {
public:
    vector<double> outerTrees(vector<vector<int>> &trees) {
        n = (int) trees.size();
        for (int i = 0; i < n; i++) {
            q[i] = {trees[i][0], trees[i][1]};
        }
        random_shuffle(q, q + n);
        Circle c({q[0], 0});
        for (int i = 1; i < n; i++)
            if (dcmp(c.r, get_dist(c.p, q[i])) < 0) {
                c = {q[i], 0};
                for (int j = 0; j < i; j++)
                    if (dcmp(c.r, get_dist(c.p, q[j])) < 0) {
                        c = {(q[i] + q[j]) / 2, get_dist(q[i], q[j]) / 2};
                        for (int k = 0; k < j; k++)
                            if (dcmp(c.r, get_dist(c.p, q[k])) < 0)
                                c = get_circle(q[i], q[j], q[k]);
                    }
            }
        return {c.p.x, c.p.y, c.r};
    }
};