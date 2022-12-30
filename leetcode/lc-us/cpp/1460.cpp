#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr) {
        int cnt[1001] = {};
        for (int i = 0; i < target.size(); i++) {
            cnt[target[i]]++;
            cnt[arr[i]]--;
        }
        for (int i = 1; i <= 1000; i++) {
            if (cnt[i]) {
                return false;
            }
        }
        return true;
    }
};