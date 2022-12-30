#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<string, string> map;
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string prefix = "http://tinyurl.com/";

    string get_rand() {
        string rand_string;
        for (int i = 0; i < 10; i++) {
            default_random_engine e(random() % 62);
            rand_string += alphabet[e() % 62];
        }
        return rand_string;
    }

public:
    string encode(string longUrl) {
        string rand_string = get_rand();
        while (map.count(rand_string)) {
            rand_string = get_rand();
        }
        map[rand_string] = move(longUrl);
        return prefix + rand_string;
    }

    string decode(string shortUrl) {
        return map[shortUrl.substr(prefix.length())];
    }
};