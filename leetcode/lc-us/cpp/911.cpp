#include <bits/stdc++.h>

using namespace std;

class TopVotedCandidate {
    int cur_candidate;
    int cur_max_vote;
    priority_queue<pair<int, int>> heap;
    unordered_map<int, int> cnt;
    vector<int> candidates;
    vector<int> _times;
public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times) {
        _times = times;
        for (int &person: persons) {
            cnt[person]++;
            heap.push({cnt[person], person});
            if (heap.top().first == cnt[person]) {
                cur_candidate = person;
                cur_max_vote = heap.top().first;
                candidates.push_back(person);
            } else {
                if (heap.top().first == cur_max_vote) candidates.push_back(cur_candidate);
                else candidates.push_back(heap.top().second);
            }
        }
    }

    int q(int t) {
        return candidates[upper_bound(_times.begin(), _times.end(), t) - _times.begin() - 1];
    }
};