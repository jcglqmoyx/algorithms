#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wordsTyping(vector<string> &sentence, int rows, int cols) {
        int res = 0, n = (int) sentence.size();
        vector<pair<int, int>> dp(n);
        for (int i = 0; i < n; i++) {
            int len = 0, cnt = 0, j = i;
            while (len <= cols) {
                int size = (int) sentence[j % n].size();
                if (size > cols) return 0;
                if (len + size <= cols) len += size + 1;
                else break;
                j++;
                if (j % n == 0) cnt++;
            }
            dp[i] = {j, cnt};
        }
        int row = 0, i = 0;
        while (row < rows) {
            int cnt = dp[i % n].second;
            res += cnt;
            i = dp[i % n].first;
            row++;
        }
        return res;
    }
};