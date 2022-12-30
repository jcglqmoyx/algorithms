#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_set<string> set;
        for (string email: emails) {
            string simplified_email;
            int index = (int) email.find('@');
            for (int i = 0; i < index; i++) {
                if (email[i] == '+') {
                    break;
                } else if (email[i] != '.') {
                    simplified_email += email[i];
                }
            }
            simplified_email += email.substr(index);
            set.insert(simplified_email);
        }
        return (int) set.size();
    }
};