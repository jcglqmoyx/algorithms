#include <bits/stdc++.h>

using namespace std;

class ValidWordAbbr {
    string abbr(string &str) {
        return str.length() <= 2 ? str : str.front() + to_string(str.size() - 2) + str.back();
    }

    unordered_map<string, unordered_set<string>> map;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string &str: dictionary) {
            string abbreviation = abbr(str);
            map[abbreviation].insert(str);
        }
    }

    bool isUnique(string word) {
        string abbreviation = abbr(word);
        if (map.find(abbreviation) == map.end()) {
            return true;
        } else if (map[abbreviation].size() == 1) {
            for (auto &str: map[abbreviation]) {
                if (str == word) return true;
            }
        }
        return false;
    }
};