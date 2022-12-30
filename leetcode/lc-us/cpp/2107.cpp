#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shareCandies(vector<int> &candies, int k) {
        int n = (int) candies.size();
        unordered_map<int, int> hash;
        for (int candy: candies) hash[candy]++;
        int res = 0;
        for (int i = 0; i < n; i++) {
            hash[candies[i]]--;
            if (i >= k) {
                hash[candies[i - k]]++;
            }
            if (hash[candies[i]] == 0) {
                hash.erase(candies[i]);
            }
            if (i >= k - 1) res = max(res, (int) hash.size());
        }
        return res;
    }
};