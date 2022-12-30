#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kIncreasing(vector<int> &arr, int k) {
        int res = 0, n = (int) arr.size();
        for (int i = 0; i < k; i++) {
            vector<int> seq = {arr[i]};
            for (int j = i + k; j < n; j += k) {
                if (arr[j] >= seq.back()) seq.push_back(arr[j]);
                else seq[upper_bound(seq.begin(), seq.end(), arr[j]) - seq.begin()] = arr[j];
            }
            res += (n - i + k - 1) / k - (int) seq.size();
        }
        return res;
    }
};