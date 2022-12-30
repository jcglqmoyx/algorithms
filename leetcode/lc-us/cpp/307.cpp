#include <bits/stdc++.h>

using namespace std;

class NumArray {
    int n;
    vector<int> tree;
    vector<int> *original_nums;

    int low_bit(int x) {
        return x & -x;
    }

    void modify(int x, int dt) {
        while (x <= n) {
            tree[x] += dt;
            x += low_bit(x);
        }
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += tree[x];
            x -= low_bit(x);
        }
        return res;
    }

public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        original_nums = &nums;
        tree.resize(n + 1);
        for (int i = 0; i < n; i++) {
            modify(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        modify(index + 1, val - (*original_nums)[index]);
        (*original_nums)[index] = val;
    }

    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};