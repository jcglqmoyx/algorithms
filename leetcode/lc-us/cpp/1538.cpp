#include <bits/stdc++.h>

using namespace std;

class ArrayReader {
public:
    int query(int a, int b, int c, int d);

    int length();
};

class Solution {
public:
    int guessMajority(ArrayReader &reader) {
        int n = reader.length();
        int v[n];
        v[0] = 0;
        int q0123 = reader.query(0, 1, 2, 3);
        if (q0123 == 4) {
            v[1] = v[2] = v[3] = 0;
        } else {
            int q0234 = reader.query(0, 2, 3, 4);
            int q1234 = reader.query(1, 2, 3, 4);
            v[1] = q0234 != q1234;
            int q0134 = reader.query(0, 1, 3, 4);
            v[2] = q0134 == q0234 ? v[1] : v[1] ^ 1;
            int q0124 = reader.query(0, 1, 2, 4);
            v[3] = q0124 == q0134 ? v[2] : v[2] ^ 1;
        }
        int prev = q0123;
        for (int i = 4; i < n; i++) {
            int q = reader.query(i - 3, i - 2, i - 1, i);
            v[i] = q == prev ? v[i - 4] : v[i - 4] ^ 1;
            prev = q;
        }
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            if (!v[i]) cnt0++;
        }
        int cnt1 = n - cnt0;

        if (cnt0 == cnt1) return -1;
        else if (cnt0 > cnt1) {
            for (int i = 0; i < n; i++) {
                if (!v[i]) {
                    return i;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (v[i]) {
                    return i;
                }
            }
        }
        return -1;
    }
};