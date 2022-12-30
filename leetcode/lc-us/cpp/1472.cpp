#include <bits/stdc++.h>

using namespace std;

class BrowserHistory {
    int p;
    vector<string> urls;
public:
    BrowserHistory(string homepage) {
        urls.push_back(homepage);
        p = 0;
    }

    void visit(string url) {
        urls.push_back(url);
        urls = vector<string>(urls.begin(), urls.begin() + p + 1);
        urls.push_back(url);
        p++;
    }

    string back(int steps) {
        if (steps > p) {
            p = 0;
        } else {
            p -= steps;
        }
        return urls[p];
    }

    string forward(int steps) {
        if (steps >= urls.size() - p) {
            p = (int) urls.size() - 1;
        } else {
            p += steps;
        }
        return urls[p];
    }
};