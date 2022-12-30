#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
        int ans = get(fruits, startPos, k);
        startPos = -startPos;
        for (auto &fruit: fruits) {
            fruit[0] = -fruit[0];
        }
        reverse(fruits.begin(), fruits.end());
        return max(ans, get(fruits, startPos, k));
    }

private:
    static int get(vector<vector<int>> &fruits, int pos, int k) {
        int n = (int) fruits.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (fruits[mid][0] <= pos) l = mid;
            else r = mid - 1;
        }
        int ans = 0;
        int cnt = 0;
        for (int i = 0, j = 0; i <= l; i++) {
            if (pos - fruits[i][0] >= 0 && pos - fruits[i][0] <= k) {
                if (j == 0) j = i;
                while (j <= l) cnt += fruits[j][1], j++;
                while (j < (int) fruits.size() && pos - fruits[i][0] + fruits[j][0] - fruits[i][0] <= k) {
                    cnt += fruits[j][1];
                    j++;
                }
                if (i && pos - fruits[i - 1][0] <= k) cnt -= fruits[i - 1][1];
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};