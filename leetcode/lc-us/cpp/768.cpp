#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        stack<int> stk;
        for (int x: arr) {
            if (stk.empty() || x >= stk.top()) {
                stk.push(x);
            } else {
                int mx = stk.top();
                stk.pop();
                while (!stk.empty() && stk.top() > x) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return (int) stk.size();
    }
};