#include <bits/stdc++.h>

using namespace std;

class Robot {
public:
    Robot(int width, int height) {
        w = width, h = height;
        d = 0;
        x = 0, y = 0;
    }

    void step(int num) {
        int round = (w + h - 2) << 1;
        num %= round;
        if (!num) {
            if (!x && !y) d = 3;
            else if (!x && y == h - 1) d = 2;
            else if (!y && x == w - 1) d = 0;
            else if (x == w - 1 && y == h - 1) d = 1;
        }
        while (num) {
            int s = 0;
            if (d == 0) s = min(num, w - 1 - x), x += s;
            else if (d == 1) s = min(num, h - 1 - y), y += s;
            else if (d == 2) s = min(num, x), x -= s;
            else if (d == 3) s = min(num, y), y -= s;
            num -= s;
            if (num) d = (d + 1) % 4;
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return directions[d];
    }

private:
    int w, h;
    int d;
    int x, y;
    const string directions[4] = {"East", "North", "West", "South"};
};