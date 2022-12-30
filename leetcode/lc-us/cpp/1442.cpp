#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &arr) {
        unordered_map<int, int> cnt, total;
        int ans = 0, s = 0;
        for (int k = 0; k < arr.size(); ++k) {
            int val = arr[k];
            if (cnt.count(s ^ val)) {
                ans += cnt[s ^ val] * k - total[s ^ val];
            }
            cnt[s]++;
            total[s] += k;
            s ^= val;
        }
        return ans;
    }
};