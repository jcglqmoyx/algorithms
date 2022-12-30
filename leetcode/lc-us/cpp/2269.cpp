#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int p[10] = {};
        p[0] = 1;
        for (int i = 1; i < 10; i++) p[i] = p[i - 1] * 10;
        vector<int> v;
        int t = num;
        while (t) v.push_back(t % 10), t /= 10;
        int n = (int) v.size();
        if (n < k) return 0;
        int res = 0;
        int x = 0;
        int i = n - 1, j = n - 1;
        for (; j - i + 1 <= k; i--) {
            x = x * 10 + v[i];
        }
        if (num % x == 0) res++;
        while (~i) {
            x = x * 10 + v[i];
            x -= p[j - i] * v[j];
            if (x && num % x == 0) res++;
            i--;
            j--;
        }
        return res;
    }
};