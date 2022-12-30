#include <bits/stdc++.h>

using namespace std;

class TextEditor {
private:
    list<char> l;
    list<char>::iterator cur;

    string get_text() {
        string s;
        auto it = cur;
        for (int k = 10; k && it != l.begin(); k--) {
            it = prev(it);
            s.push_back(*it);
        }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    TextEditor() {
        cur = l.begin();
    }

    void addText(string text) {
        for (char c: text) l.insert(cur, c);
    }

    int deleteText(int k) {
        int cnt = 0;
        for (; k && cur != l.begin(); --k) {
            cnt++;
            l.erase(prev(cur));
        }
        return cnt;
    }

    string cursorLeft(int k) {
        for (; k && cur != l.begin(); k--) {
            cur = prev(cur);
        }
        return get_text();
    }

    string cursorRight(int k) {
        for (; k && cur != l.end(); k--) {
            cur = next(cur);
        }
        return get_text();
    }
};