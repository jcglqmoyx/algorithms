#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (abs(a) == abs(b)) return a < b;
            return abs(a) < abs(b);
        });
        unordered_map<int, int> hash;
        for (int x: arr) hash[x]++;
        for (int x: arr) {
            if (!hash.count(x)) continue;
            if (hash.count(x * 2)) {
                hash[x]--, hash[x * 2]--;
                if (hash[x] == 0) hash.erase(x);
                if (hash[x * 2] == 0) hash.erase(x * 2);

            } else return false;
        }
        return true;
    }
};