#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool is_ipv4(string &s) {
        int dots = 0, n = (int) s.size();
        for (int i = 0, j = 0; i < n; i++) {
            if (s[i] == '.') {
                if (i == n - 1) return false;
                dots++;
                string str = s.substr(j, i - j);
                if (str.empty() || str.size() > 4) return false;
                for (char c: str) if (!isdigit(c)) return false;
                if (str.length() >= 2 && str.substr(0, 1) == "0") return false;
                int x = stoi(str);
                if (x < 0 || x > 255) return false;
                j = i + 1;
            } else if (i == n - 1) {
                string str = s.substr(j, i - j + 1);
                for (char c: str) if (!isdigit(c)) return false;
                if (str.length() >= 2 && str.substr(0, 1) == "0") return false;
                int x = stoi(str);
                if (x < 0 || x > 255) return false;
            }
        }
        return dots == 3;
    }

    bool is_ipv6(string &s) {
        int colons = 0, n = (int) s.size();
        for (int i = 0, j = 0; i < n; i++) {
            if (s[i] == ':') {
                if (i == n - 1) return false;
                colons++;
                string str = s.substr(j, i - j);
                for (char c: str) if (!isdigit(c) && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return false;
                if (str.length() < 1 || str.length() > 4) return false;
                j = i + 1;
            } else if (i == n - 1) {
                string str = s.substr(j, i - j + 1);
                for (char c: str) if (!isdigit(c) && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return false;
                if (str.length() < 1 || str.length() > 4) return false;
            }
        }
        return colons == 7;
    }

public:
    string validIPAddress(string IP) {
        if (is_ipv4(IP)) return "IPv4";
        if (is_ipv6(IP)) return "IPv6";
        return "Neither";
    }
};