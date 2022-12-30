#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        size = 0, cap = capacity;
        head = new DLinkedList, tail = new DLinkedList(0, head, nullptr);
        head->next = tail;
    }

    int get(int key) {
        if (hash.count(key)) {
            auto node = hash[key];
            move_to_end(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (hash.count(key)) {
            auto node = hash[key];
            move_to_end(node);
            node->val = value;
        } else {
            auto node = new DLinkedList(value, tail->prev, tail);
            tail->prev->next = node, tail->prev = node;
            hash[key] = node;
            node->key = key;
            size++;
            if (size > cap) {
                delete_front();
                size--;
            }
        }
    }

private:
    struct DLinkedList {
        int key, val;
        DLinkedList *prev, *next;

        DLinkedList() : val(0), prev(nullptr), next(nullptr) {}

        DLinkedList(int _val, DLinkedList *_prev, DLinkedList *_next) : val(_val), prev(_prev), next(_next) {}
    };

    int size, cap;
    unordered_map<int, DLinkedList *> hash;
    DLinkedList *head, *tail;

    void move_to_end(DLinkedList *node) {
        auto prev = node->prev, next = node->next;
        prev->next = next, next->prev = prev;
        node->prev = tail->prev, node->next = tail;
        tail->prev->next = node, tail->prev = node;
    }

    void delete_front() {
        auto node = head->next;
        auto prev = head, next = node->next;
        prev->next = next, next->prev = prev;
        hash.erase(node->key);
        delete node;
    }
};