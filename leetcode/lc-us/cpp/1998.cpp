#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> p, rk;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void connect(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rk[px] > rk[py]) swap(px, py);
        p[px] = py;
        rk[py] += rk[px];
    }

public:
    bool gcdSort(vector<int> &nums) {
        int size = *max_element(nums.begin(), nums.end()) + 1;
        p.resize(size), rk.resize(size, 1);
        for (int i = 0; i < size; i++) p[i] = i;
        for (int x: nums) {
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    connect(x, i);
                    connect(x, x / i);
                }
            }
        }
        vector<int> t = nums;
        sort(t.begin(), t.end());
        for (int i = 0; i < (int) nums.size(); i++) {
            if (find(nums[i]) != find(t[i])) return false;
        }
        return true;
    }
};