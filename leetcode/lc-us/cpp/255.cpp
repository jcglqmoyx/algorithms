#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int> &preorder) {
        int root = INT32_MIN;
        stack<int> stk;
        for (int num: preorder) {
            if (num < root) return false;
            while (!stk.empty() && stk.top() < num) {
                root = stk.top();
                stk.pop();
            }
            stk.push(num);
        }
        return true;
    }
};