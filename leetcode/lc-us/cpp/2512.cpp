#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k) {
        int n = (int) student_id.size();
        struct T {
            int id;
            int score;

            bool operator<(const T &t) const {
                if (score == t.score) return id < t.id;
                return score > t.score;
            }
        };

        unordered_set<string> P, N;
        for (auto &x: positive_feedback) P.insert(x);
        for (auto &x: negative_feedback) N.insert(x);
        vector<T> v;
        for (int i = 0; i < n; i++) {
            int s = 0;
            auto r = report[i];
            stringstream ss(r);
            string w;
            while (ss >> w) {
                if (P.count(w)) s += 3;
                if (N.count(w)) s -= 1;
            }
            v.push_back({student_id[i], s});
        }
        sort(v.begin(), v.end());
        while (v.size() > k) v.pop_back();
        vector<int> res(k);
        for (int i = 0; i < k; i++) res[i] = v[i].id;
        return res;
    }
};