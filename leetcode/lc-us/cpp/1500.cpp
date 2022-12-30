#include <bits/stdc++.h>

using namespace std;

class FileSharing {
public:
    FileSharing(int m) {
        id = 1;
    }

    int join(vector<int> ownedChunks) {
        int user_id;
        if (ids.empty()) user_id = id++;
        else {
            int t = *ids.begin();
            ids.erase(t);
            user_id = t;
        }
        for (int chunk: ownedChunks) {
            users[user_id].insert(chunk);
            chunks[chunk].insert(user_id);
        }
        return user_id;
    }

    void leave(int userID) {
        ids.insert(userID);
        for (auto chunk: users[userID]) {
            chunks[chunk].erase(userID);
            if (chunks[chunk].empty()) chunks.erase(chunk);
        }
        users.erase(userID);
    }

    vector<int> request(int userID, int chunkID) {
        vector<int> res;
        for (int user: chunks[chunkID]) {
            res.push_back(user);
        }
        if (chunks.count(chunkID) && !chunks[chunkID].empty() && !chunks[chunkID].count(userID)) {
            chunks[chunkID].insert(userID);
            users[userID].insert(chunkID);
        }
        return res;
    }

private:
    int id;
    set<int> ids;
    unordered_map<int, unordered_set<int>> users;
    unordered_map<int, set<int>> chunks;
};