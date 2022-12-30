#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, 0, n * 2);
        return res;
    }

private:
    string str;
    vector<string> res;

    void dfs(int left, int right, int index, int k) {
        if (right > left || left > k / 2) return;
        if (index == k) {
            res.push_back(str);
            return;
        }
        str.push_back('(');
        dfs(left + 1, right, index + 1, k);
        str.pop_back();
        str.push_back(')');
        dfs(left, right + 1, index + 1, k);
        str.pop_back();
    }
};