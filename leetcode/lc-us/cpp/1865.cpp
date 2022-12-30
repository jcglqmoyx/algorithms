#include <bits/stdc++.h>

using namespace std;

class FindSumPairs {
    vector<int> a1, a2;
    unordered_map<int, int> cnt;
public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
        a1 = nums1, a2 = nums2;
        for (int num: nums2) {
            cnt[num]++;
        }
    }

    void add(int index, int val) {
        int tmp = a2[index];
        cnt[tmp]--;
        if (cnt[tmp] == 0) cnt.erase(tmp);
        a2[index] += val;
        cnt[a2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (int num: a1) {
            int diff = tot - num;
            if (cnt.find(diff) != cnt.end()) {
                res += cnt[diff];
            }
        }
        return res;
    }
};