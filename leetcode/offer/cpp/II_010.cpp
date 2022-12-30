#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0, cnt = 0;
        for (int num: nums) {
            sum += num;
            hash[sum]++;
            if (hash.count(sum - k)) {
                if (k == 0) cnt += hash[sum - k] - 1;
                else cnt += hash[sum - k];
            }
        }
        return cnt;
    }
};