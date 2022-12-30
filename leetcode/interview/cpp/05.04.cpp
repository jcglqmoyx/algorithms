#include <bits/stdc++.h>

using namespace std;

class Solution {
    int bit_cnt;
    vector<int> v;

    int get_next_smallest() {
        vector<int> bits = v;

        int cnt_front = 0;
        for (int bit: bits) {
            if (bit) cnt_front++;
            else break;
        }
        if (cnt_front == bit_cnt) {
            long long x = 1;
            for (int i = 0; i < (int) bits.size() - bit_cnt + 1; i++) x <<= 1;
            for (int i = 0; i < bit_cnt - 1; i++) x = x * 2 + 1;
            if (x >= INT32_MAX) return -1;
            return (int) x;

        } else {
            int cnt_right = 0;
            for (int i = (int) bits.size() - 1; i; i--) {
                if (bits[i]) cnt_right++;
                if (bits[i] && !bits[i - 1]) {
                    swap(bits[i], bits[i - 1]);
                    cnt_right--;
                    int j = (int) bits.size() - 1;
                    for (; cnt_right; j--, cnt_right--) {
                        bits[j] = 1;
                    }
                    for (int k = j; k > i; k--) bits[k] = 0;
                    break;
                }
            }
            int x = 0;
            for (int bit: bits) x = x * 2 + bit;
            return x;
        }
    }

    int get_next_largest() {
        vector<int> bits = v;

        if (bit_cnt == (int) bits.size()) return -1;
        for (int i = (int) bits.size() - 1; i; i--) {
            if (!bits[i] && bits[i - 1]) {
                swap(bits[i], bits[i - 1]);
                for (int j = i + 1, k = i + 1; k < bits.size(); k++) {
                    if (bits[k]) {
                        bits[j] = bits[k];
                        if (k != j) bits[k] = 0;
                        j++;
                    }
                }
                break;
            }
        }
        int x = 0;
        for (int bit: bits) x = x * 2 + bit;
        return x;
    }

public:
    vector<int> findClosedNumbers(int num) {
        bit_cnt = __builtin_popcount(num);

        int t = num;
        while (t) v.push_back(t & 1), t >>= 1;
        reverse(v.begin(), v.end());

        return {get_next_smallest(), get_next_largest()};
    }
};