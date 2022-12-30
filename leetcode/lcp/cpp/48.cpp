#include <bits/stdc++.h>

using namespace std;

using PII = pair<int, int>;
using PLL = pair<long, long>;
constexpr PII dirs[4] = {{0, 1},
                         {1, 0},
                         {1, 1},
                         {1, -1}};

int ptr_uf[10000], cnt_uf[10000];

void init_uf(int n) {
    for (int i = 0; i < n; ++i) {
        ptr_uf[i] = i;
        cnt_uf[i] = 1;
    }
}

int find_uf(int i) {
    return i == ptr_uf[i] ? i : (ptr_uf[i] = find_uf(ptr_uf[i]));
}

void add_uf(int i, int j) {
    i = find_uf(i);
    j = find_uf(j);
    if (i != j) {
        cnt_uf[i] += cnt_uf[j];
        cnt_uf[j] = 0;
        ptr_uf[j] = i;
    }
}

inline long codec(int x, int y, int color) {
    constexpr int W = 31;
    constexpr long D = 1e9 + 10;
    return ((((x + D) << W) | (y + D)) << 1) | color;
}

inline tuple<int, int, int> decode(long c) {
    constexpr long W = 31, M = (1L << W) - 1;
    constexpr long D = 1e9 + 10;
    return {((c >> (W + 1)) & M) - D, ((c >> 1) & M) - D, c & 1};
}

class Solution {
    unordered_set<long> piece_set;

    unordered_set<long> check_one_step(vector<vector<int>> &pieces, int color) {
        int other_color = 1 - color;
        unordered_set<long> win_steps;
        for (auto &p: pieces) {
            if (p[2] == color) {
                int x0 = p[0], y0 = p[1];
                for (auto[dx, dy]: dirs) {
                    for (int d = 0; d < 5; ++d) {
                        int x1 = x0 - d * dx, y1 = y0 - d * dy, n1 = 0, n2 = 0, x2, y2;
                        for (int x = x1, y = y1, k = 0; k < 5; ++k, x += dx, y += dy) {
                            if (piece_set.count(codec(x, y, color))) {
                                ++n1;
                            } else if (piece_set.count(codec(x, y, other_color))) {
                                ++n2;
                            } else {
                                x2 = x, y2 = y;
                            }
                        }
                        if (n1 == 4 and n2 == 0) {
                            win_steps.insert(codec(x2, y2, color));
                        }
                    }
                }
            }
        }
        return win_steps;
    }

    bool check_two_step(vector<vector<int>> &pieces, int color) {
        int other_color = 1 - color;
        vector<PLL> win_steps;
        unordered_set<long> pts;
        long buf[10];
        for (auto &p: pieces) {
            if (p[2] == color) {
                int x0 = p[0], y0 = p[1];
                for (auto[dx, dy]: dirs) {
                    for (int d = 0; d < 5; ++d) {
                        int x1 = x0 - d * dx, y1 = y0 - d * dy, n1 = 0, n2 = 0, l = 0;
                        for (int x = x1, y = y1, k = 0; k < 5; ++k, x += dx, y += dy) {
                            if (piece_set.count(codec(x, y, color))) {
                                ++n1;
                            } else if (piece_set.count(codec(x, y, other_color))) {
                                ++n2;
                            } else {
                                buf[l++] = codec(x, y, color);
                            }
                        }
                        if (n1 == 3 and n2 == 0) {
                            win_steps.emplace_back(buf[0], buf[1]);
                            pts.insert(buf[0]);
                            pts.insert(buf[1]);
                        }
                    }
                }
            }
        }
        unordered_map<long, int> pt_ids;
        for (auto p: pts) {
            int i = pt_ids.size();
            pt_ids[p] = i;
        }
        init_uf(pt_ids.size());
        for (auto[p1, p2]: win_steps) {
            int i1 = pt_ids[p1], i2 = pt_ids[p2];
            add_uf(i1, i2);
        }
        for (int i = 0, n = pt_ids.size(); i < n; ++i) {
            if (cnt_uf[i] >= 3) {
                return true;
            }
        }
        return false;
    }

public:
    string gobang(vector<vector<int>> &pieces) {
        for (auto &p: pieces) {
            piece_set.insert(codec(p[0], p[1], p[2]));
        }
        auto black_one_steps = check_one_step(pieces, 0);
        auto white_one_steps = check_one_step(pieces, 1);
        if (black_one_steps.size() >= 1) {
            return "Black";
        } else if (white_one_steps.size() >= 2) {
            return "White";
        } else if (white_one_steps.size() >= 1) {
            auto[black_x0, black_y0, black_c0] = decode(*white_one_steps.begin());
            pieces.push_back({black_x0, black_y0, 0});
            piece_set.insert(codec(black_x0, black_y0, 0));
            auto black_steps_v2 = check_one_step(pieces, 0);
            if (black_steps_v2.size() >= 2) {
                return "Black";
            } else {
                return "None";
            }
        } else if (check_two_step(pieces, 0)) {
            return "Black";
        } else {
            return "None";
        }
    }
};