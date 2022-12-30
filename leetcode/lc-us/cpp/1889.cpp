#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes) {
        typedef long long LL;
        const int MOD = 1e9 + 7;

        sort(packages.begin(), packages.end());
        int mx = packages.back();
        vector<LL> s((int) packages.size() + 1);
        for (int i = 1; i <= packages.size(); i++) {
            s[i] = s[i - 1] + packages[i - 1];
        }
        for (auto &b: boxes) sort(b.begin(), b.end(), greater<>());
        sort(boxes.begin(), boxes.end(), greater<>());
        int n = (int) boxes.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (boxes[mid].front() < mx) r = mid - 1;
            else l = mid;
        }
        if (boxes[r].front() < mx) return -1;
        LL res = 1e18;
        for (int i = 0; i <= r; i++) {
            LL cur = 0;
            auto b = boxes[i];
            int size = (int) b.size();
            int offset = 0;
            for (int j = size - 1; j >= 0; j--) {
                LL p = upper_bound(packages.begin() + offset, packages.end(), b[j]) - packages.begin();
                cur += b[j] * (p - offset) - (s[p] - s[offset]);
                offset = p;
                if (cur > res) break;
            }
            if (cur < res) res = cur;
        }
        return (int) (res % MOD);
    }
};