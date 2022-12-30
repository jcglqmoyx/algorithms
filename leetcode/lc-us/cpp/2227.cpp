#include <bits/stdc++.h>

using namespace std;

class Encrypter {
    unordered_map<char, string> S;
    unordered_map<string, int> cnt;
public:
    Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dictionary) {
        for (int i = 0; i < keys.size(); i++) {
            S[keys[i]] = values[i];
        }
        for (const auto &s: dictionary) cnt[encrypt(s)]++;
    }

    string encrypt(string word1) {
        string res;
        for (char c: word1) {
            if (!S.count(c)) return "";
            res += S[c];
        }
        return res;
    }

    int decrypt(string word2) {
        return cnt.count(word2) ? cnt[word2] : 0;
    }
};