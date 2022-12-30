#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        LL x = ip2LL(ip);
        vector<string> res;
        while (n) {
            int low_bit = (int) (x & -x);
            int len = get_len(low_bit);
            if (low_bit == 0) {
                len = 1;
                while (1 << len <= n) len++;
                res.push_back(get(x, 32 - len + 1));
                n -= 1 << (len - 1);
                x += 1 << (len - 1);
            } else if (low_bit <= n) {
                res.push_back(get(x, 32 - len + 1));
                n -= low_bit;
                x += low_bit;
            } else {
                while (n < 1 << len) len--;
                res.push_back(get(x, 32 - len));
                x += 1 << len;
                n -= 1 << len;
            }
        }
        return res;
    }

private:
    using LL = long long;

    static string get(LL x, int pre_len) {
        stack<string> stk;
        for (int i = 0; i < 4; i++) {
            stk.push(to_string(x & 255));
            x >>= 8;
            stk.push(".");
        }
        stk.pop();
        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        res += '/' + to_string(pre_len);
        return res;
    }

    static int get_len(int x) {
        int len = 0;
        while (x) {
            len++;
            x >>= 1;
        }
        return len;
    }

    static LL ip2LL(string &ip) {
        LL res = 0;
        int n = (int) ip.size();
        for (int i = 0; i < n; i++) {
            int x = 0;
            int j = i;
            while (j < n && ip[j] != '.') {
                x = x * 10 + ip[j] - '0';
                j++;
            }
            i = j;
            res = res * 256 + x;
        }
        return res;
    }
};