#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(vector<int> &mapping, int x) {
        string s = to_string(x);
        for (char &c: s) {
            int d = c - '0';
            c = (char) (mapping[d] + '0');
        }
        return stoi(s);
    }

public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
        unordered_map<int, int> M;
        for (int x: nums) {
            M[x] = get(mapping, x);
        }
        sort(nums.begin(), nums.end(), [&](int x, int y) {
            return M[x] < M[y];
        });
        return nums;
    }
};