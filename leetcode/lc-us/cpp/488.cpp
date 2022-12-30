#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<string, int> dp;

    string clean(const string &s) {
        string res;
        vector<pair<char, int>> st;

        for (auto c: s) {
            while (!st.empty() && c != st.back().first && st.back().second >= 3) {
                st.pop_back();
            }
            if (st.empty() || c != st.back().first) {
                st.emplace_back(c, 1);
            } else {
                st.back().second++;
            }
        }
        if (!st.empty() && st.back().second >= 3) {
            st.pop_back();
        }
        for (auto &e: st) {
            for (int j = 0; j < e.second; ++j) {
                res.push_back(e.first);
            }
        }
        return res;
    }

    int dfs(const string &board, const string &hand) {
        if (board.empty()) {
            return 0;
        }
        if (dp.count(board + " " + hand)) {
            return dp[board + " " + hand];
        }

        int res = 6;
        for (int j = 0; j < hand.size(); ++j) {
            if (j > 0 && hand[j] == hand[j - 1]) {
                continue;
            }
            for (int i = 0; i <= board.size(); ++i) {
                if (i > 0 && board[i - 1] == hand[j]) {
                    continue;
                }
                bool choose = false;
                if (i < board.size() && board[i] == hand[j]) {
                    choose = true;
                }
                if (i > 0 && i < board.size() && board[i - 1] == board[i] && board[i] != hand[j]) {
                    choose = true;
                }
                if (choose) {
                    string new_board = clean(board.substr(0, i) + hand[j] + board.substr(i));
                    string new_hand = hand.substr(0, j) + hand.substr(j + 1);
                    res = min(res, dfs(new_board, new_hand) + 1);
                }
            }
        }
        dp[board + " " + hand] = res;
        return res;
    }

public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        int ans = dfs(board, hand);
        return ans <= 5 ? ans : -1;
    }
};