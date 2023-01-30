#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int> &encoded) {
        int n = (int) encoded.size() + 1;
//        int sum = 0;
//        for (int i = 1; i <= n; i++) {
//            sum ^= i;
//        }
        int sum = n % 4 == 1;
        int t = 0;
        for (int i = 1; i < n - 1; i += 2) {
            t ^= encoded[i];
        }
        vector<int> res(n);
        res[0] = sum ^ t;
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] ^ encoded[i - 1];
        }
        return res;
    }
};