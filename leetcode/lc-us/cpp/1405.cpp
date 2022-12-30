#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        vector<pair<int, char>> v = {{a, 'a'},
                                     {b, 'b'},
                                     {c, 'c'}};
        while (v[0].first || v[1].first || v[2].first) {
            sort(v.begin(), v.end(), greater<>());
            int num = min(v[0].first, 2);
            if (!res.empty() && res.back() == v[0].second) num = 1;
            for (int i = 0; i < num; i++) res.push_back(v[0].second);
            v[0].first -= num;
            if (!v[1].first) break;
            res.push_back(v[1].second);
            v[1].first--;
        }
        return res;
    }
};