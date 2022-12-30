#include <bits/stdc++.h>

using namespace std;

class Logger {
    unordered_map<string, int> map;
public:
    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (map.count(message) && timestamp - map[message] < 10) {
            return false;
        } else {
            map[message] = timestamp;
            return true;
        }
    }
};