#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getStrongest(vector<int> &arr, int k) {
        vector<int> res(k);
        sort(arr.begin(), arr.end());
        int n = (int) arr.size();
        int median = arr[(n - 1) / 2];
        int l = 0, h = n - 1;
        for (int i = 0; i < k; i++) {
            if (arr[h] - median >= median - arr[l]) {
                res[i] = arr[h--];
            } else {
                res[i] = arr[l++];
            }
        }
        return res;
    }
};