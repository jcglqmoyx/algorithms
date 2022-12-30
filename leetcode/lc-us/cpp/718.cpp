#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ULL = unsigned long long;
    const int P = 13331;

    int n, m;
    vector<ULL> h1, h2, p;

    ULL get(vector<ULL> h, int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    bool check(int len) {
        unordered_set<ULL> hash;
        for (int i = len; i <= n; i++) hash.insert(get(h1, i - len + 1, i));
        for (int i = len; i <= m; i++) if (hash.count(get(h2, i - len + 1, i))) return true;
        return false;
    }

public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        n = (int) nums1.size(), m = (int) nums2.size();
        h1.resize(n + 1), h2.resize(m + 1), p.resize(n + 1);
        for (int i = 1; i <= n; i++) h1[i] = h1[i - 1] * P + nums1[i - 1];
        for (int i = 1; i <= m; i++) h2[i] = h2[i - 1] * P + nums2[i - 1];
        p[0] = 1;
        for (int i = 1; i <= n; i++) p[i] = p[i - 1] * P;
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};