#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int> &arr) {
        int MOD = 1e9 + 7;
        long long res = 0;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> hash;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j <= i; j++) {
                int x = arr[i], y = arr[j];
                if (j == i) hash[x]++;
                else if (x % y == 0) {
                    if (hash.count(x / y)) {
                        hash[x] += hash[y] * hash[x / y];
                    }
                }
            }
            res += hash[arr[i]];
            res %= MOD;
        }
        return (int) res;
    }
};