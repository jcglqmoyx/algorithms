#include <bits/stdc++.h>

using namespace std;

class Solution {
    int N = 2e4 + 5;
    vector<int> tr;

    static int low_bit(int x) {
        return x & -x;
    }

    void update(int x, int dt) {
        while (x <= N - 1) {
            tr[x] += dt;
            x += low_bit(x);
        }
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += tr[x];
            x -= low_bit(x);
        }
        return res;
    }

public:
    vector<int> countSmaller(vector<int> &nums) {
        tr.resize(N);
        int n = (int) nums.size();
        vector<int> res(n);
        for (int i = n - 1; ~i; i--) {
            update(nums[i] + 10001, 1);
            int count = query(nums[i] + 10000);
            res[i] = count;
        }
        return res;
    }
};