#include <bits/stdc++.h>

using namespace std;

class Solution {
    using VVI = vector<vector<int>>;

    int get(VVI &v1, VVI &v2, int a, int b) {
        if ((int) v1.size() == 1) return a + b - v2[0][0];
        return a - v1[1][0] + b - v2[0][0];
    }

public:
    int minimumOperations(vector<int> &nums) {
        int n = (int) nums.size();
        if (n == 1) return 0;
        unordered_map<int, int> cnt1, cnt2;
        for (int i = 0; i < n; i += 2) {
            cnt1[nums[i]]++;
        }
        for (int i = 1; i < n; i += 2) {
            cnt2[nums[i]]++;
        }
        VVI v1, v2;
        for (auto[num, freq]: cnt1) v1.push_back({freq, num});
        for (auto[num, freq]: cnt2) v2.push_back({freq, num});
        sort(v1.begin(), v1.end(), greater<>());
        sort(v2.begin(), v2.end(), greater<>());
        int a = (n + 1) >> 1, b = n >> 1;
        if (v1[0][1] != v2[0][1]) return n - v1[0][0] - v2[0][0];
        return min(get(v1, v2, a, b), get(v2, v1, b, a));
    }
};