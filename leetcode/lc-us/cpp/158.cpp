int read4(char *buf4);

class Solution {
    int len = 0, idx = 0;
    char cache[4]{};

public:
    int read(char *buf, int n) {
        int i = 0;
        while (i < n) {
            if (!len) len = read4(cache);
            if (!len) break;
            if (idx < len) {
                buf[i] = cache[idx];
                i++, idx++;
            } else {
                idx = 0, len = 0;
            }
        }
        return i;
    }
};