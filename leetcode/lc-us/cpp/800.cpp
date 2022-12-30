#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int INF = 1e9;
    unordered_map<char, int> map;

    int diff(string &a, string &b) {
        int tmp = abs(map[a[0]] * 16 + map[a[1]] - map[b[0]] * 16 - map[b[1]]);
        return tmp * tmp;
    }

public:
    string similarRGB(string color) {
        for (int i = 0; i <= 9; i++) map[i + '0'] = i;
        for (int i = 'a'; i <= 'f'; i++) map[i] = i - 'a' + 10;
        string res;
        for (int i = 1; i < color.size(); i += 2) {
            string str = color.substr(i, 2);
            int min_similarity = INF;
            string most_similar_color;
            for (auto[k, v]: map) {
                string tmp;
                tmp.push_back(k);
                tmp.push_back(k);
                int similarity = diff(tmp, str);
                if (similarity < min_similarity) {
                    min_similarity = similarity;
                    most_similar_color = tmp;
                }
            }
            res += most_similar_color;
        }
        return "#" + res;
    }
};