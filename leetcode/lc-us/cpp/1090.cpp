#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit) {
        int n = (int) values.size();
        vector<pair<int, int>> pairs;
        pairs.reserve(n);
        for (int i = 0; i < n; i++) {
            pairs.emplace_back(values[i], labels[i]);
        }
        sort(pairs.begin(), pairs.end(), greater<>());
        unordered_map<int, int> cnt;
        int res = 0;
        for (auto p: pairs) {
            if (cnt[p.second] < use_limit) {
                res += p.first;
                cnt[p.second]++;
                num_wanted--;
                if (!num_wanted) break;
            }
        }
        return res;
    }
};