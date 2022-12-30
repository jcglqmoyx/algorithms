#include <bits/stdc++.h>

using namespace std;

class Vector2D {
public:
    Vector2D(vector<vector<int>> &vec) {
        x = vec.begin();
        end = vec.end();
        y = 0;
    }

    int next() {
        move_to_next();
        return (*x)[y++];
    }

    bool hasNext() {
        move_to_next();
        return x != end;
    }

private:
    vector<vector<int>>::iterator x;
    vector<vector<int>>::iterator end;
    int y;

    void move_to_next() {
        while (x < end && y == (*x).size()) {
            x++;
            y = 0;
        }
    }
};