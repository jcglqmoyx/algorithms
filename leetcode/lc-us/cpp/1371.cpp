#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int res = 0, status = 0;
        vector<int> pos(1 << 5, -1);
        pos[0] = 0;
        for (int i = 1; i <= s.size(); i++) {
            switch (s[i - 1]) {
                case 'a':
                    status ^= 1 << 0;
                    break;
                case 'e':
                    status ^= 1 << 1;
                    break;
                case 'i':
                    status ^= 1 << 2;
                    break;
                case 'o':
                    status ^= 1 << 3;
                    break;
                case 'u':
                    status ^= 1 << 4;
                    break;
                default:
                    break;
            }
            if (~pos[status]) res = max(res, i - pos[status]);
            else pos[status] = i;
        }
        return res;
    }
};