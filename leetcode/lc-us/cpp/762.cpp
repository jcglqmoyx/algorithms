#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> prime_nums = {2, 3, 5, 7, 11, 13, 17, 19};
        int count = 0;
        for (int i = L; i <= R; i++) {
            if (prime_nums.count(get(i))) {
                count++;
            }
        }
        return count;
    }
};