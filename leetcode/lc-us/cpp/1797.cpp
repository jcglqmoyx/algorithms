#include <bits/stdc++.h>

using namespace std;

struct DLinkedList {
public:
    int expire_time;
    string token;
    DLinkedList *prev;
    DLinkedList *next;

    DLinkedList() : expire_time(), token(), prev(nullptr), next(nullptr) {}

    DLinkedList(int _expire_time) : expire_time(_expire_time), token(), prev(nullptr), next(nullptr) {}
};

class AuthenticationManager {
    int time_to_live;
    DLinkedList *head, *tail;
    unordered_map<string, DLinkedList *> map;
public:
    AuthenticationManager(int timeToLive) {
        time_to_live = timeToLive;
        head = new DLinkedList();
        tail = new DLinkedList();
        head->next = tail;
        tail->prev = head;
    }

    void generate(string tokenId, int currentTime) {
        auto *node = new DLinkedList(currentTime + time_to_live);
        DLinkedList *prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
        map[tokenId] = node;
    }

    void renew(string tokenId, int currentTime) {
        if (map.find(tokenId) != map.end() && map[tokenId]->expire_time > currentTime) {
            DLinkedList *node = map[tokenId];
            DLinkedList *prev = node->prev, *next = node->next;
            prev->next = next;
            next->prev = prev;

            node->expire_time = currentTime + time_to_live;

            DLinkedList *pre = tail->prev;
            pre->next = node;
            node->prev = pre;
            node->next = tail;
            tail->prev = node;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        DLinkedList *cur = head->next;
        while (cur != tail) {
            if (cur->expire_time <= currentTime) {
                map.erase(cur->token);
                DLinkedList *prev = cur->prev, *next = cur->next;
                prev->next = next;
                next->prev = prev;
            } else {
                count++;
            }
            cur = cur->next;
        }
        return count;
    }
};