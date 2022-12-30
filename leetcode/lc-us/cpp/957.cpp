#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n) {
        unordered_set<int> st;
        vector<int> states;
        while (true) {
            vector<int> cur(8);
            for (int i = 1; i <= 6; i++) cur[i] = (cells[i - 1] == cells[i + 1]);
            int state = 0;
            for (int i = 0; i < 8; i++) state = state * 2 + cur[i];
            if (st.count(state)) break;
            st.insert(state);
            states.push_back(state);
            cells = cur;
        }
        int mod = (int) st.size();
        n = (n - 1) % mod;
        int res = states[n];
        vector<int> v;
        v.reserve(8);
        for (int i = 0; i < 8; i++, res >>= 1) v.push_back(res & 1);
        reverse(v.begin(), v.end());
        return v;
    }
};