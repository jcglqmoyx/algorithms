#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> to_delete;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') left++;
            else if (c == ')') {
                right++;
                if (right > left) to_delete.insert(i), right--;
            }
        }
        if (left > right) {
            int diff = left - right;
            for (int i = (int) s.size() - 1; i >= 0 && diff; i--) {
                if (s[i] == '(') diff--, to_delete.insert(i);
            }
        }
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (to_delete.count(i)) continue;
            res.push_back(s[i]);
        }
        return res;
    }
};