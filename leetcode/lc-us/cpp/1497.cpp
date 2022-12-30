#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int> &arr, int k) {
        unordered_map<int, int> cnt;
        for (int num: arr) {
            int index = num % k;
            if (index < 0) {
                if (cnt[-index]) {
                    cnt[-index]--;
                } else if (cnt[-k - index]) {
                    cnt[-k - index]--;
                } else {
                    cnt[index]++;
                }
            } else {
                if (cnt[k - index]) {
                    cnt[k - index]--;
                } else if (cnt[-index]) {
                    cnt[-index]--;
                } else {
                    cnt[index]++;
                }
            }
        }
        return all_of(cnt.begin(), cnt.end(), [](const auto &it) {
            if (it.second) {
                return !it.first && it.second % 2 == 0;
            }
            return true;
        });
    }
};