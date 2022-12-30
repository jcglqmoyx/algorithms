#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;
    using VI = vector<int>;
    using UMII = unordered_map<int, int>;

    int calc(UMII &hash1, UMII hash2) {
        int cnt = 0;
        for (auto &[k1, v1]: hash1) {
            LL square = (LL) k1 * k1;
            for (auto &[k2, v2]: hash2) {
                if (square % k2 == 0) {
                    int k3 = (int) (square / k2);
                    if (k3 == k2) {
                        cnt += v1 * v2 * (v2 - 1) / 2;
                    } else if (k2 < k3 && hash2.count(k3)) {
                        cnt += v1 * v2 * hash2[(int) (square / k2)];
                    }
                }
            }
        }
        return cnt;
    }

public:
    int numTriplets(vector<int> &nums1, vector<int> &nums2) {
        UMII hash1, hash2;
        for (int num: nums1) hash1[num]++;
        for (int num: nums2) hash2[num]++;
        return calc(hash1, hash2) + calc(hash2, hash1);
    }
};