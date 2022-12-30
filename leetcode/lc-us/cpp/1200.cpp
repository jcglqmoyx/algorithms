#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int min_diff = 2000000;
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] - arr[i] == min_diff) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};