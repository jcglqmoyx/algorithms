#include <bits/stdc++.h>

using namespace std;

struct DLinkedNode {
    int key;
    int val;
    DLinkedNode *prev, *next;

    DLinkedNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int capacity;
    int size;
    DLinkedNode *head, *tail;
    unordered_map<int, DLinkedNode *> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        DLinkedNode *node = cache[key];
        move_to_first(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->val = value;
            move_to_first(cache[key]);
            return;
        }
        auto *node = new DLinkedNode();
        node->key = key;
        node->val = value;
        move_to_first(node);
        cache[key] = node;
        size++;
        if (size > capacity) {
            delete_end();
        }
    }

    void move_to_first(DLinkedNode *node) {
        if (node->prev == head) return;
        if (!node->prev) {
            DLinkedNode *next = head->next;
            node->next = next;
            next->prev = node;
            head->next = node;
            node->prev = head;
            return;
        }
        DLinkedNode *prev = node->prev;
        DLinkedNode *next = node->next;
        prev->next = next;
        next->prev = prev;

        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void delete_end() {
        DLinkedNode *end = tail->prev;
        cache.erase(end->key);
        DLinkedNode *prev = end->prev;
        prev->next = tail;
        tail->prev = prev;
        delete end;
        size--;
    }
};