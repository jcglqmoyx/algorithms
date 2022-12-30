#include <bits/stdc++.h>

using namespace std;

class Solution {
    static int bit_count(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & 1)) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }

    static bool cmp(int a, int b) {
        int m = bit_count(a), n = bit_count(b);
        if (m != n) {
            return m < n;
        } else {
            return a < b;
        }
    }

public:
    vector<int> sortByBits(vector<int> &arr) {
        sort(arr.begin(), arr.end(), &cmp);
        return arr;
    }
};