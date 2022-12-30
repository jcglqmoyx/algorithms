#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int beautifulBouquet(vector<int> &flowers, int k) {
        int MOD = 1e9 + 7;
        int n = (int) flowers.size();
        int res = 0;
        map<int, int> M;
        unordered_map<int, int> cnt;
        for (int i = 0, j = 0; j < n; j++) {
            cnt[flowers[j]]++;
            M[cnt[flowers[j]]]++;
            while (M.rbegin()->first > k) {
                cnt[flowers[i]]--;
                int count_flower_i = cnt[flowers[i]];
                M[count_flower_i]++;
                if (--M[count_flower_i + 1] == 0) {
                    M.erase(count_flower_i + 1);
                }
                i++;
            }
            res = (res + j - i + 1) % MOD;
        }
        return res;
    }
};