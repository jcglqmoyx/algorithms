#include <bits/stdc++.h>

using namespace std;

class Solution {
    int tr[1000001]{}, max_age;

    int low_bit(int x) { return x & -x; }

    int query(int x) {
        int res = 0;
        while (x) res = max(res, tr[x]), x -= low_bit(x);
        return res;
    }

    void update(int x, int val) {
        while (x <= max_age) tr[x] = max(tr[x], val), x += low_bit(x);
    }

public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = (int) scores.size();
        max_age = *max_element(ages.begin(), ages.end());
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {scores[i], ages[i]};
        }
        sort(v.begin(), v.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            int score = v[i].first, age = v[i].second, cur = score + query(age);
            update(age, cur);
            res = max(res, cur);
        }
        return res;
    }
};