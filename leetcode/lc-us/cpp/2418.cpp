#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        using pis = pair<int, string>;

        int n = (int) names.size();
        vector<pis> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {heights[i], names[i]};
        }
        sort(v.begin(), v.end(), greater<>());
        vector<string> res(n);
        for (int i = 0; i < n; i++) res[i] = v[i].second;
        return res;
    }
};