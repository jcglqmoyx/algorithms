#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int n = (int) message.size();
        int t = n;
        for (int i = 1; i <= n; i++) {
            if (get(i, limit) >= n) {
                vector<string> res;
                for (int j = 1, k = 0; j <= i; j++) {
                    string suffix = "<" + to_string(j) + "/" + to_string(i) + ">";
                    int len = min(limit - (int) suffix.size(), t);
                    t -= len;
                    res.push_back(message.substr(k, len) + suffix);
                    k += len;
                }
                return res;
            }
        }
        return {};
    }

private:
    int get(int n, int limit) {
        int len = (int) to_string(n).size();
        int res = n * (limit - 3 - len);
        int s = 0;
        for (int i = 1, t = 9; i < len; i++, t *= 10) {
            res -= i * t;
            s += t;
        }
        res -= (n - s) * len;
        return res;
    }
};