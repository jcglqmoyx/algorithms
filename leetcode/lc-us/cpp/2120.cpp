#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m =(int) s.size();
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            int x = startPos[0], y = startPos[1];
            int cnt = m - i;
            for (int j = i; j < m; ++j) {
                char ch = s[j];
                if (ch == 'L') {
                    --y;
                }
                else if (ch == 'R') {
                    ++y;
                }
                else if (ch == 'U') {
                    --x;
                }
                else {
                    ++x;
                }
                if (x < 0 || x >= n || y < 0 || y >= n) {
                    cnt = j - i;
                    break;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};