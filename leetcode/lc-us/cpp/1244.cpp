#include <bits/stdc++.h>

using namespace std;

class Leaderboard {
public:
    Leaderboard() {
        memset(scores, 0, sizeof(scores));
    }

    void addScore(int playerId, int score) {
        scores[playerId] += score;
    }

    int top(int K) {
        copy(scores, scores + N, tmp);
        quick_select(K, 1, N - 1);
        int sum = 0;
        for (int i = 1; i <= K; i++) sum += tmp[i];
        return sum;
    }

    void reset(int playerId) {
        scores[playerId] = 0;
    }

private:
    static const int N = 10010;
    int scores[N];
    int tmp[N];

    int quick_select(int k, int l, int r) {
        if (l >= r) return l;
        int pivot = tmp[l];
        int i = l + 1, j = r;
        while (true) {
            while (i < r && tmp[i] > pivot) i++;
            while (j > l && tmp[j] < pivot) j--;
            if (i >= j) break;
            swap(tmp[i], tmp[j]);
            i++, j--;
        }
        swap(tmp[l], tmp[j]);
        if (j == k) return j;
        if (j < k) return quick_select(k, j + 1, r);
        else return quick_select(k, l, j - 1);
    }
};