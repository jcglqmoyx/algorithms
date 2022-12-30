#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> fenwick_tree;
    int n;

    int low_bit(int x) { return x & -x; }

    void update(int x) {
        while (x <= n) {
            fenwick_tree[x] += 1;
            x += low_bit(x);
        }
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += fenwick_tree[x];
            x -= low_bit(x);
        }
        return res;
    }

public:
    int reversePairs(vector<int> &nums) {
        int res = 0;
        n = (int) nums.size();
        fenwick_tree.resize(n + 1);
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for (int &num: nums) num = (int) (lower_bound(temp.begin(), temp.end(), num) - temp.begin()) + 1;
        for (int i = (int) nums.size() - 1; i >= 0; i--) {
            res += query(nums[i] - 1);
            update(nums[i]);
        }
        return res;
    }
};