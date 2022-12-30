#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int> &code, int k) {
        int n = (int) code.size();
        vector<int> res(n);
        if (!k) return res;
        int sum = 0;
        if (k < 0) {
            for (int i = 0; i < -k; i++) sum += code[i];
            for (int i = 0; i < n; i++) {
                res[(i - k + n) % n] = sum;
                sum -= code[i];
                sum += code[(i - k + n) % n];
            }
        } else {
            for (int i = 0; i < k; i++) sum += code[i];
            for (int i = 0; i < n; i++) {
                res[(i - 1 + n) % n] = sum;
                sum -= code[i];
                sum += code[(i + k) % n];
            }
        }
        return res;
    }
};