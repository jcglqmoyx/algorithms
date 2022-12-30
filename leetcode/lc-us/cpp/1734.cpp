#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int> &encoded) {
        int n = (int) encoded.size();
        vector<int> res(n + 1);
        int sum = 0;
        for (int i = 0; i < n; i += 2) {
            sum ^= encoded[i];
        }
        for (int num = 1; num <= n + 1; num++) {
            sum ^= num;
        }
        res[n] = sum;
        for (int i = n - 1; ~i; i--) {
            res[i] = sum ^ encoded[i];
            sum = res[i];
        }
        return res;
    }
};