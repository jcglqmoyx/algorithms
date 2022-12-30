#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string> &folder) {
        int n = (int) folder.size();
        sort(folder.begin(), folder.end());
        vector<bool> st(n);
        vector<string> res;
        for (int i = 0; i < n; i++) {
            if (!st[i]) {
                res.push_back(folder[i]);
                int j = i + 1;
                while (j < n && folder[j].substr(0, folder[i].size() + 1) == folder[i] + '/') {
                    st[j] = true;
                    j++;
                }
                i = j - 1;
            }
        }
        return res;
    }
};