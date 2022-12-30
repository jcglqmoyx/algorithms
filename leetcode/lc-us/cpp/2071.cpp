#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength) {
        int n = (int) tasks.size(), m = (int) workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto check = [&](int mid) {
            multiset<int> S(workers.begin() + m - mid, workers.end());
            int p = pills;
            for (int i = mid - 1; i >= 0; i--) {
                if (*S.rbegin() >= tasks[i]) {
                    S.erase(prev(S.end()));
                } else {
                    if (!p) return false;
                    auto it = S.lower_bound(tasks[i] - strength);
                    if (it == S.end()) return false;
                    p--;
                    S.erase(it);
                }
            }
            return true;
        };

        int l = 0, r = min(n, m);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};