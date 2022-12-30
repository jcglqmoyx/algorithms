#include <bits/stdc++.h>

using namespace std;

class LogSystem {
public:
    LogSystem() {
        string s[6] = {"Year", "Month", "Day", "Hour", "Minute", "Second"};
        for (int i = 0; i < 6; i++) idx[s[i]] = i;
    }

    void put(int id, string timestamp) {
        hash[get(timestamp, "", false)] = id;
    }

    vector<int> retrieve(string start, string end, string granularity) {
        LL l = get(start, granularity, false), r = get(end, granularity, true);
        vector<int> res;
        auto it = hash.lower_bound(l);
        while (it != hash.end() && it->first < r) res.push_back(it->second), it++;
        return res;
    }

private:
    using LL = long long;
    map<LL, int> hash;
    unordered_map<string, int> idx;

    LL get(string &t, const string &granularity, bool flag) {
        vector<LL> v;
        for (int i = 0; i < t.size();) {
            int it = (int) t.find(':', i);
            if (it >= 0) v.push_back(stoll(t.substr(i, it - i))), i = it + 1;
            else {
                v.push_back(stoll(t.substr(i)));
                break;
            }
        }
        return calc(v, granularity, flag);
    }

    LL calc(vector<LL> t, const string &granularity, bool end) {
        if (!granularity.empty()) {
            if (end) t[idx[granularity]]++;
            for (int i = idx[granularity] + 1; i < 6; i++) t[i] = 0;
        }
        return (t[0] * 13 * 32 + t[1] * 32 + t[2]) * 86400LL + t[3] * 3600LL + t[4] * 60L + t[5];
    }
};