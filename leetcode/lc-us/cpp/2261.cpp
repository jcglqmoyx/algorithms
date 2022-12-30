#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDistinct(vector<int> &nums, int k, int m) {
        using ULL = unsigned long long;
        const int P = 13331;

        int n = (int) nums.size();

        vector<ULL> h(n + 1), p(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + nums[i - 1];
        }

        auto get = [&](int l, int r) {
            return h[r] - h[l - 1] * p[r - l + 1];
        };

        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1];
            if (nums[i - 1] % m == 0) s[i]++;
        }
        unordered_set<ULL> S;
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                if (s[j] - s[i - 1] <= k) {
                    S.insert(get(i, j));
                }
            }
        }
        return (int) S.size();
    }
};