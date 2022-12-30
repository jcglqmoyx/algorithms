#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minAbbreviation(string target, vector<string> &dictionary) {
        int size = (int) target.size();
        vector<int> sames;
        for (const auto &str: dictionary) {
            if (str.size() != size) {
                continue;
            }
            int same = 0;
            for (int i = 0; i < size; ++i) {
                if (str[i] != target[i]) {
                    same += 1 << i;
                }
            }
            sames.push_back(same);
        }
        if (sames.empty()) {
            return to_string(size);
        }

        int n = 1 << size;
        int minAbbrSize = size;
        int minAbbr = n - 1;
        for (int i = 0; i < n; ++i) {
            auto r = std::find_if(sames.begin(), sames.end(), [&](const auto &item) {
                return (item & i) == 0;
            });
            if (r != sames.end()) {
                continue;
            }
            int abbrSize = getAbbrSize(i, size);
            if (abbrSize < minAbbrSize) {
                minAbbrSize = abbrSize;
                minAbbr = i;
            }
        }
        return getAbbrStr(minAbbr, target);
    }

    int getAbbrSize(int i, int size) {
        bool lastChar = false;
        int r = size;
        for (int j = 0; j < size; ++j, i >>= 1) {
            if (i & 1) {
                lastChar = true;
            } else {
                if (lastChar) {
                    r++;
                }
                r--;
                lastChar = false;
            }
        }
        return r;
    }

    string getAbbrStr(int i, const string &word) {
        int size = (int) word.size();
        int num = 0;
        string r;
        for (int j = 0; j < size; ++j, i >>= 1) {
            if (i & 1) {
                if (num != 0) {
                    r.append(to_string(num));
                    num = 0;
                }
                r.push_back(word[j]);
            } else {
                num++;
            }
        }
        if (num) {
            r.append(to_string(num));
        }
        return r;
    }
};