#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int> &digits) {
        int cnt[10] = {};
        for (int x: digits) cnt[x]++;
        vector<int> res;
        for (int i = 100; i <= 998; i += 2) {
            int x = i % 10, y = (i / 10) % 10, z = i / 100;
            cnt[x]--, cnt[y]--, cnt[z]--;
            if (cnt[x] >= 0 && cnt[y] >= 0 && cnt[z] >= 0) res.push_back(i);
            cnt[x]++, cnt[y]++, cnt[z]++;
        }
        return res;
    }
};