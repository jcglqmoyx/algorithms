#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get_steps(int cur, long long n) {
        int steps = 0;
        long long first = cur, last = cur;
        while (first <= n) {
            steps += (int) (min(last, n) - first + 1);
            first *= 10, last = last * 10 + 9;
        }
        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while (k) {
            int step = get_steps(cur, n);
            if (step <= k) cur++, k -= step;
            else cur *= 10, k--;
        }
        return cur;
    }
};