#include <bits/stdc++.h>

using namespace std;

class StringIterator {
    string str;
    int pointer = 0;
public:
    StringIterator(string compressedString) {
        int len = (int) compressedString.size();
        for (int i = 0; i < len; i++) {
            if (!isalpha(compressedString[i])) {
                int j = i;
                while (j < len && isdigit(compressedString[j])) {
                    j++;
                }
                int num = stoi(compressedString.substr(i, j - i));
                if (num > 100) num = 100;
                for (int count = 0; count < num; count++) {
                    str.push_back(compressedString[i - 1]);
                }
                i = j == len ? j : j - 1;
            }
        }
    }

    char next() {
        return hasNext() ? str[pointer++] : ' ';
    }

    bool hasNext() {
        return pointer < str.length();
    }
};