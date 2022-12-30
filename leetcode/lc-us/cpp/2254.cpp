#include <bits/stdc++.h>

using namespace std;

class VideoSharingPlatform {
    set<int> deleted_ids;
    unordered_map<int, string> contents;
    unordered_map<int, int> views, likes, dislikes;
public:
    VideoSharingPlatform() {
    }

    int upload(string video) {
        int id;
        if (deleted_ids.empty()) {
            id = (int) contents.size();
        } else {
            id = *deleted_ids.begin();
            deleted_ids.erase(deleted_ids.begin());
        }
        contents[id] = move(video);
        return id;
    }

    void remove(int videoId) {
        if (contents.erase(videoId)) {
            deleted_ids.insert(videoId);
        }
    }

    string watch(int videoId, int startMinute, int endMinute) {
        if (!contents.count(videoId)) return "-1";
        views[videoId]++;
        return contents[videoId].substr(startMinute, min(endMinute + 1, (int) contents[videoId].size()) - startMinute);
    }

    void like(int videoId) {
        if (contents.count(videoId)) {
            likes[videoId]++;
        }
    }

    void dislike(int videoId) {
        if (contents.count(videoId)) {
            dislikes[videoId]++;
        }
    }

    vector<int> getLikesAndDislikes(int videoId) {
        if (contents.count(videoId)) {
            return {likes[videoId], dislikes[videoId]};
        } else {
            return {-1};
        }
    }

    int getViews(int videoId) {
        if (contents.count(videoId)) return views[videoId];
        return -1;
    }
};