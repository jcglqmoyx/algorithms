#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int r = k % 10;
        if (r % 2 == 0 || r % 5 == 0) return -1;
        int len = 1;
        int num = 1;
        while (num < k) {
            num = num * 10 + 1;
            len++;
        }
        unordered_set<int> remainders;
        while (true) {
            while (num >= k) {
                num %= k;
                if (num == 0) {
                    return len;
                }
                if (remainders.count(num)) return -1;
                remainders.insert(num);
                while (num < k) {
                    num = num * 10 + 1;
                    len++;
                }
            }
        }
        return -1;
    }
};