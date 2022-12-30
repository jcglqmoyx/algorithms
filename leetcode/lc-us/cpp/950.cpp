#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        int n = (int) deck.size();
        vector<int> res(n);
        deque<int> indices;
        for (int i = 0; i < n; i++) {
            indices.push_back(i);
        }
        sort(deck.begin(), deck.end());
        for (int card: deck) {
            res[indices.front()] = card;
            indices.pop_front();
            if (!indices.empty()) {
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }
        return res;
    }
};