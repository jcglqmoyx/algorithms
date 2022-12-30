#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool is_letter_log(const string &log) {
        return isalpha(log[log.find(' ') + 1]);
    }

    static bool cmp(const string &a, const string &b) {
        int idx1 = a.find(' '), idx2 = b.find(' ');
        string log1 = a.substr(idx1), log2 = b.substr(idx2);
        if (log1 != log2) {
            return log1 < log2;
        } else {
            return a.substr(0, idx1) < b.substr(0, idx2);
        }
    }

public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        vector<string> res, digit_logs;
        for (const string &log: logs) {
            if (is_letter_log(log)) {
                res.push_back(log);
            } else {
                digit_logs.push_back(log);
            }
        }
        sort(res.begin(), res.end(), &cmp);
        for (const string &log: digit_logs) {
            res.push_back(log);
        }
        return res;
    }
};