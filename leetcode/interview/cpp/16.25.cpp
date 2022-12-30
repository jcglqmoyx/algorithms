#include <bits/stdc++.h>

using namespace std;

struct DLinkedNode {
    int key;
    int val;
    DLinkedNode *prev, *next;

    DLinkedNode() : key(0), val(0), prev(nullptr), next(nullptr) {}

    DLinkedNode(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    DLinkedNode *head, *tail;
    int size, capacity;
    unordered_map<int, DLinkedNode *> cache;
public:
    LRUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
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
        auto *node = new DLinkedNode(key, value);
        move_to_first(node);
        cache[key] = node;
        size++;
        if (size > capacity) {
            delete_last();
        }
    }

    void move_to_first(DLinkedNode *node) {
        if (head->next == node) return;
        if (!node->prev) {
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;
            return;
        }
        DLinkedNode *prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;

        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void delete_last() {
        DLinkedNode *to_delete = tail->prev, *prev = to_delete->prev;
        prev->next = tail;
        tail->prev = prev;
        cache.erase(to_delete->key);
        delete to_delete;
        size--;
    }
};