#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_set<int> s;

    bool contains_equal_digits(int h, int m) {
        unordered_set<int> s1;
        if (h < 10) s1.insert(0);
        if (m < 10) s1.insert(0);
        while (h) {
            s1.insert(h % 10);
            h /= 10;
        }
        while (m) {
            s1.insert(m % 10);
            m /= 10;
        }
        return all_of(s1.begin(), s1.end(), [&](int x) {
            return s.count(x);
        });
    }

public:
    string nextClosestTime(string time) {
        string res;
        int hour = stoi(time.substr(0, 2)), minute = stoi(time.substr(3, 2));
        int hh = hour, mm = minute;
        if (hh < 10) s.insert(0);
        if (mm < 10) s.insert(0);
        while (hh) {
            s.insert(hh % 10);
            hh /= 10;
        }
        while (mm) {
            s.insert(mm % 10);
            mm /= 10;
        }
        for (int h = hour; h <= 23; h++) {
            int m;
            if (h == hour) m = minute + 1;
            else m = 0;
            for (; m <= 59; m++) {
                if (contains_equal_digits(h, m)) {
                    if (h < 10) res += '0';
                    res += to_string(h) + ':';
                    if (m < 10) res += '0';
                    res += to_string(m);
                    return res;
                }
            }
        }
        for (int h = 0; h <= hour; h++) {
            for (int m = 0; m <= 59; m++) {
                if (contains_equal_digits(h, m)) {
                    if (h < 10) res += '0';
                    res += to_string(h) + ':';
                    if (m < 10) res += '0';
                    res += to_string(m);
                    return res;
                }
            }
        }
        return "00:00";
    }
};