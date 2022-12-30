#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string> &username, vector<int> &timestamp, vector<string> &website) {
        const char DELIMITER = ' ';

        vector<Record> records;
        records.reserve(username.size());
        for (int i = 0; i < username.size(); i++) {
            records.push_back({username[i], website[i], timestamp[i]});
        }
        sort(records.begin(), records.end());

        unordered_map<string, vector<string>> hash;
        for (auto &record: records) {
            hash[record.username].push_back(record.website);
        }
        unordered_map<string, int> freq;
        for (auto &[_, v]: hash) {
            unordered_set<string> set;
            if (v.size() < 3) continue;
            int n = (int) v.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        set.insert(v[i] + DELIMITER + v[j] + DELIMITER + v[k]);
                    }
                }
            }
            for (const auto &s: set) freq[s]++;
        }
        string s;
        int max_freq = 0;
        for (auto &[k, v]: freq) {
            if (v > max_freq) {
                max_freq = v;
                s = k;
            } else if (v == max_freq) {
                s = min(s, k);
            }
        }
        int idx1 = (int) s.find(DELIMITER), idx2 = (int) s.rfind(DELIMITER);
        return {s.substr(0, idx1), s.substr(idx1 + 1, idx2 - idx1 - 1), s.substr(idx2 + 1)};
    }

private:
    struct Record {
        string username, website;
        int timestamp;

        bool operator<(const Record &r) const {
            if (timestamp != r.timestamp) return timestamp < r.timestamp;
            else return website < r.website;
        }
    };
};