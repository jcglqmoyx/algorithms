#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        int n = (int) security.size();
        vector<int> l(n), r(n);
        for (int i = 1, cnt = 0; i < n; i++) {
            if (security[i] <= security[i - 1]) cnt++;
            else cnt = 0;
            l[i] = cnt;
        }
        for (int i = n - 2, cnt = 0; i >= 0; i--) {
            if (security[i] <= security[i + 1]) cnt++;
            else cnt = 0;
            r[i] = cnt;
        }
        vector<int> res;
        for (int i = time; i < n - time; i++) {
            if (l[i] >= time && r[i] >= time) res.push_back(i);
        }
        return res;
    }
};