#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string> &names) {
        vector<string> res;
        unordered_map<string, int> map;
        for (string &name: names) {
            if (!map.count(name)) {
                res.push_back(name);
                map[name] = 0;
            } else {
                for (int index = map[name] + 1;; index++) {
                    string new_name = name + '(' + to_string(index) + ')';
                    if (!map.count(new_name)) {
                        res.push_back(new_name);
                        map[name] = index;
                        map[new_name] = 0;
                        break;
                    }
                }
            }
        }
        return res;
    }
};