#include <bits/stdc++.h>

using namespace std;

class Bitset {
    int n;
    int cnt0, cnt1, cnt_flip;
    int bits[100005];
public:
    Bitset(int size) {
        n = size;
        cnt0 = n, cnt1 = cnt_flip = 0;
        memset(bits, 0, sizeof bits);
    }

    void fix(int idx) {
        int &x = bits[idx];
        if (cnt_flip & 1) {
            if (x == 1) {
                x = 0;
                cnt0--, cnt1++;
            }
        } else {
            if (x == 0) {
                x = 1;
                cnt0--, cnt1++;
            }
        }
    }

    void unfix(int idx) {
        int &x = bits[idx];
        if (cnt_flip & 1) {
            if (x == 0) {
                x = 1;
                cnt1--, cnt0++;
            }
        } else {
            if (x == 1) {
                x = 0;
                cnt1--, cnt0++;
            }
        }
    }

    void flip() {
        swap(cnt0, cnt1);
        cnt_flip++;
    }

    bool all() {
        return cnt1 == n;
    }

    bool one() {
        return cnt1;
    }

    int count() {
        return cnt1;
    }

    string toString() {
        string s;
        if (cnt_flip & 1) {
            for (int i = 0; i < n; i++) {
                if (bits[i] == 0) {
                    s.push_back('1');
                } else {
                    s.push_back('0');
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (bits[i] == 0) {
                    s.push_back('0');
                } else {
                    s.push_back('1');
                }
            }
        }
        return s;
    }
};