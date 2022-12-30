#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string> &nums) {
        int n = (int) nums.size();
        string res(n, '0');
        unordered_set<string> s;
        for (auto &num: nums) s.insert(num);
        for (int i = 0; i < 1 << n; i++) {
            string str;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) str.push_back('1');
                else str.push_back('0');
            }
            if (!s.count(str)) return str;
        }
        return "";
    }
};