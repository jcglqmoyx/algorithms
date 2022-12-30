#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int> &arr) {
        int n = (int) arr.size();
        vector<int> f(n);
        unordered_set<int> s;
        for (int num: arr) s.insert(num);
        for (int i = n - 1; i >= 2; i--) {
            for (int j = i - 1; j >= 1 && arr[i] - arr[j] < arr[j]; j--) {
                int count = 0;
                if (s.count(arr[i] - arr[j])) {
                    count = 2;
                    int a = arr[i], b = arr[j], diff = a - b;
                    while (s.count(diff)) {
                        count++;
                        a = b;
                        b = diff;
                        diff = a - b;
                        if (diff >= b) break;
                    }
                }
                f[i] = max(f[i], count);
            }
        }
        int res = 0;
        for (int i: f) res = max(res, i);
        return res;
    }
};