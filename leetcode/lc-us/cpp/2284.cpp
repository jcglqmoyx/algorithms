#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders) {
        unordered_map<string, int> map;
        for (int i = 0; i < messages.size(); i++) {
            auto &message = messages[i];
            auto &sender = senders[i];
            int cnt = 1;
            for (char c: message) {
                if (c == ' ') cnt++;
            }
            map[sender] += cnt;
        }
        string res;
        int max_cnt = 0;
        for (auto &[sender, cnt]: map) {
            if (cnt > max_cnt) max_cnt = cnt, res = sender;
            else if (cnt == max_cnt && sender > res) res = sender;
        }
        return res;
    }
};