#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        int mx = 3 * (1 << (n - 1));
        if (k > mx) return "";
        string res;
        if (k <= 1 << (n - 1)) res.push_back('a');
        else if (k <= 1 << n) res.push_back('b'), k -= 1 << (n - 1);
        else res.push_back('c'), k -= 1 << n;
        for (int i = 1; i < n; i++) {
            bool st[3] = {false};
            st[res.back() - 'a'] = true;
            int t;
            if (k > 1 << (n - i - 1)) k -= 1 << (n - i - 1), t = 2;
            else t = 1;
            for (int j = 0, cnt = 0; j < 3; j++) {
                if (!st[j]) {
                    cnt++;
                    if (cnt == t) {
                        res.push_back((char) (j + 'a'));
                        break;
                    }
                }
            }
        }
        return res;
    }
};