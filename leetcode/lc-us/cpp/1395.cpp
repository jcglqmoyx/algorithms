#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> arr;

    int low_bit(int x) {
        return x & -x;
    }

    void update(int x, int dt) {
        while (x <= 1e5) {
            arr[x] += dt;
            x += low_bit(x);
        }
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += arr[x];
            x -= low_bit(x);
        }
        return res;
    }

public:
    int numTeams(vector<int> &rating) {
        arr.resize(1e5 + 1, 0);
        int n = (int) rating.size();
        vector<int> left_less(n), right_less(n), left_greater(n), right_greater(n);
        for (int i = 0; i < n; i++) {
            update(rating[i], 1);
            left_less[i] = query(rating[i] - 1);
            left_greater[i] = query(1e5) - query(rating[i]);
        }
        arr.clear();
        arr.resize(1e5 + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            update(rating[i], 1);
            right_less[i] = query(rating[i] - 1);
            right_greater[i] = query(1e5) - query(rating[i]);
        }
        int teams = 0;
        for (int i = 0; i < n; i++) {
            teams += left_greater[i] * right_less[i] + left_less[i] * right_greater[i];
        }
        return teams;
    }
};