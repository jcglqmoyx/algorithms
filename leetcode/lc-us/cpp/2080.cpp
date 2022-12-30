#include <bits/stdc++.h>

using namespace std;

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int> &arr) {
        int n = (int) arr.size();
        hash.resize(*max_element(arr.begin(), arr.end()) + 1);
        for (int i = 0; i < n; i++) {
            hash[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        if (value < hash.size() && !hash[value].empty()) {
            auto &nums = hash[value];
            auto l = lower_bound(nums.begin(), nums.end(), left);
            auto r = upper_bound(nums.begin(), nums.end(), right);
            return (int) (r - l);
        } else return 0;
    }

private:
    vector<vector<int>> hash;
};