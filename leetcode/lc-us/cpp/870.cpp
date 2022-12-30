#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        int n = (int) nums1.size();
        map<int, int> hash;
        for (int num: nums1) hash[num]++;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int num = nums2[i];
            auto p = hash.lower_bound(num);
            auto q = p;
            while (q != hash.end() && q->first == num) q++;
            if (q == hash.end()) {
                res[i] = hash.begin()->first;
                hash.begin()->second--;
                if (hash.begin()->second == 0) hash.erase(hash.begin());
            } else {
                res[i] = q->first;
                q->second--;
                if (q->second == 0) hash.erase(q);
            }
        }
        return res;
    }
};