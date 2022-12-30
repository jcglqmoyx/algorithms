#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int> &heights) {
        int n = (int) heights.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 0;
            while (!s.empty() && heights[s.top()] < heights[i]) {
                s.pop();
                cnt++;
            }
            if (s.empty()) res[i] = cnt;
            else res[i] = cnt + 1;
            s.push(i);
        }
        return res;
    }
};