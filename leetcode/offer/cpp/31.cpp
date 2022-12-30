#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        int n = (int) pushed.size();
        stack<int> stk;
        for (int i = 0, j = 0; i < pushed.size(); i++) {
            stk.push(pushed[i]);
            while (!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
        int size = (int) stk.size();
        for (int i = n - size; i < n; i++) {
            if (stk.top() != popped[i]) return false;
            stk.pop();
        }
        return true;
    }
};