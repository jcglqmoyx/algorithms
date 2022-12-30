#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int> &tree) {
        unordered_map<int, int> map;
        int res = 0;
        for (int i = 0, j = 0; j < tree.size(); j++) {
            map[tree[j]]++;
            while (map.size() > 2) {
                map[tree[i]]--;
                if (!map[tree[i]]) map.erase(tree[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};