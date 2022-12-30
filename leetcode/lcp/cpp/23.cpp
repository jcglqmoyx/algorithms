#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMagic(vector<int> &target) {
        int n = (int) target.size();
        vector<int> first;
        for (int i = 2; i <= n; i += 2) first.push_back(i);
        for (int i = 1; i <= n; i += 2) first.push_back(i);
        int j = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (target[i] != first[i]) break;
            j++, k++;
        }
        if (!k) return false;
        vector<int> pre(first.begin() + k, first.end());
        while (j < n) {
            vector<int> temp;
            for (int i = 1; i < pre.size(); i += 2) temp.push_back(pre[i]);
            for (int i = 0; i < pre.size(); i += 2) temp.push_back(pre[i]);
            pre.clear();
            for (int i = 0; i < temp.size(); i++) {
                if (i < k) {
                    if (target[j] != temp[i]) return false;
                    else j++;
                } else pre.push_back(temp[i]);
            }
        }
        return true;
    }
};