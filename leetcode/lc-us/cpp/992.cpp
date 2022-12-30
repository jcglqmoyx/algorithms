#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int> &nums, int k) {
        unordered_map<int, int> hash1, hash2;
        int res = 0;
        for (int r = 0, l1 = 0, l2 = 0; r < nums.size(); r++) {
            hash1[nums[r]]++, hash2[nums[r]]++;
            while (hash1.size() > k) {
                hash1[nums[l1]]--;
                if (hash1[nums[l1]] == 0) hash1.erase(nums[l1]);
                l1++;
            }
            while (hash2.size() > k - 1) {
                hash2[nums[l2]]--;
                if (hash2[nums[l2]] == 0) hash2.erase(nums[l2]);
                l2++;
            }
            res += l2 - l1;
        }
        return res;
    }
};