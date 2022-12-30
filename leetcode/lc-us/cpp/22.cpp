#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    string cur;

    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, 0, 2 * n);
        return res;
    }

    void backtrack(int left, int right, int index, int k) {
        if (left > k / 2 || right > left) return;
        if (index == k) {
            res.push_back(cur);
            return;
        }
        cur.push_back('(');
        backtrack(left + 1, right, index + 1, k);
        cur.pop_back();
        cur.push_back(')');
        backtrack(left, right + 1, index + 1, k);
        cur.pop_back();
    }
};