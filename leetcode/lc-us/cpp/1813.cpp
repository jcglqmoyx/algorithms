#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.length() < sentence2.length()) return areSentencesSimilar(sentence2, sentence1);
        deque<string> dq1, dq2;
        stringstream ss1(sentence1), ss2(sentence2);
        string word;
        while (ss1 >> word) dq1.push_back(word);
        while (ss2 >> word) dq2.push_back(word);
        while (true) {
            while (!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front()) {
                dq1.pop_front();
                dq2.pop_front();
            }
            while (!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back()) {
                dq1.pop_back();
                dq2.pop_back();
            }
            break;
        }
        return dq2.empty();
    }
};