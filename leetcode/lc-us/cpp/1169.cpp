#include <bits/stdc++.h>

using namespace std;

struct Transaction {
    string name;
    int time{};
    int amount{};
    string city;
    int index{};
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string> &transactions) {
        vector<Transaction> v;
        for (int i = 0; i < transactions.size(); i++) {
            string &s = transactions[i];
            Transaction t;
            int idx1 = (int) s.find(',');
            t.name = s.substr(0, idx1);
            int idx2 = (int) s.find(',', idx1 + 1);
            t.time = stoi(s.substr(idx1 + 1, idx2 - idx1 - 1));
            int idx3 = (int) s.find(',', idx2 + 1);
            t.amount = stoi(s.substr(idx2 + 1, idx3 - idx2 - 1));
            t.city = s.substr(idx3 + 1);
            t.index = i;
            v.push_back(t);
        }
        auto cmp = [&](const Transaction &a, const Transaction &b) {
            return a.time < b.time;
        };
        sort(v.begin(), v.end(), cmp);
        unordered_set<int> set;
        for (int i = 0; i < v.size(); i++) {
            if (set.count(v[i].index)) continue;
            if (v[i].amount > 1000) set.insert(v[i].index);
            else {
                bool flag = false;
                int j = i;
                while (j >= 0) {
                    if (v[i].time - v[j].time <= 60) {
                        if (v[j].name == v[i].name && v[j].city != v[i].city) {
                            set.insert(v[j].index);
                            flag = true;
                        }
                    } else break;
                    j--;
                }
                j = i;
                while (j < v.size()) {
                    if (v[j].time - v[i].time <= 60) {
                        if (v[j].name == v[i].name && v[j].city != v[i].city) {
                            set.insert(v[j].index);
                            flag = true;
                        }
                    } else break;
                    j++;
                }
                if (flag) set.insert(v[i].index);
            }
        }
        vector<string> res;
        for (auto idx: set) res.push_back(transactions[idx]);
        return res;
    }
};