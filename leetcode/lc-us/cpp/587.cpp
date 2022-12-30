#include <bits/stdc++.h>

using namespace std;

using PDD = pair<double, double>;

const int N = 3010;

int n;
PDD q[N];
int stk[N];
bool used[N];

PDD operator-(PDD a, PDD b) {
    return {a.first - b.first, a.second - b.second};
}

double cross(PDD a, PDD b) {
    return a.first * b.second - a.second * b.first;
}

double area(PDD a, PDD b, PDD c) {
    return cross(b - a, c - a);
}

vector<vector<int>> andrew() {
    sort(q, q + n);
    int top = 0;
    for (int i = 0; i < n; i++) {
        while (top >= 2 && area(q[stk[top - 1]], q[stk[top]], q[i]) < 0) {
            if (area(q[stk[top - 1]], q[stk[top]], q[i]) <= 0) used[stk[top--]] = false;
            else top--;
        }
        stk[++top] = i;
        used[i] = true;
    }
    used[0] = false;
    for (int i = n - 1; i >= 0; i--) {
        if (used[i]) continue;
        while (top >= 2 && area(q[stk[top - 1]], q[stk[top]], q[i]) < 0) top--;
        stk[++top] = i;
    }

    vector<vector<int>> res;
    for (int i = 2; i <= top; i++) {
        auto t = q[stk[i]];
        res.push_back({(int) t.first, (int) t.second});
    }
    return res;
}

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
        memset(stk, 0, sizeof stk), memset(used, false, sizeof used);
        n = (int) trees.size();
        for (int i = 0; i < n; i++) {
            q[i].first = trees[i][0];
            q[i].second = trees[i][1];
        }
        return andrew();
    }
};