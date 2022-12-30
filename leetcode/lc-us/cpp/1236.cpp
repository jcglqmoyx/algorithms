#include <bits/stdc++.h>

using namespace std;

class HtmlParser {
public:
    vector<string> getUrls(string url);
};


class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string hostname = get_hostname(startUrl);
        unordered_set<string> set;
        set.insert(startUrl);
        queue<string> q;
        q.push(startUrl);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto urls = htmlParser.getUrls(t);
            for (auto &url: urls) {
                if (get_hostname(url) != hostname || set.count(url)) continue;
                set.insert(url);
                q.push(url);
            }
        }
        return vector<string>(set.begin(), set.end());
    }

private:
    string get_hostname(string &url) {
        int low = (int) url.find("//"), high = url.find('/', low + 2);
        return url.substr(low + 2, high - low - 2);
    }
};