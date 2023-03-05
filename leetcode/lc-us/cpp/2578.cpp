#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int splitNum(int num) {
        vector<int> v;
        while (num) v.push_back(num % 10), num /= 10;
        sort(v.begin(), v.end());
        int x = 0, y = 0;
        for (int i = 0; i < v.size(); i++) {
            if (i & 1) x = x * 10 + v[i];
            else y = y * 10 + v[i];
        }
        return x + y;
    }
};