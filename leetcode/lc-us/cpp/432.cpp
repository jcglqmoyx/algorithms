#include <bits/stdc++.h>

using namespace std;

class AllOne {
    struct Node {
        int val;
        unordered_set<string> keys;
        Node *left, *right;

        explicit Node(int _val) {
            val = _val;
            left = right = nullptr;
        }
    };

    Node *head, *tail;
    unordered_map<string, Node *> map;

    static Node *add_to_right(Node *node, string &key, int val) {
        if (node->right->val == val) {
            node->right->keys.insert(key);
            return node->right;
        }
        auto right = node->right;
        auto new_node = new Node(val);
        new_node->keys.insert(key);
        new_node->left = node, node->right = new_node;
        new_node->right = right, right->left = new_node;
        return new_node;
    }

    static void delete_node(Node *node) {
        auto left = node->left, right = node->right;
        left->right = right, right->left = left;
        delete node;
    }

public:
    AllOne() {
        head = new Node(INT32_MIN), tail = new Node(INT32_MAX);
        head->right = tail, tail->left = head;
    }

    void inc(string key) {
        if (map.find(key) == map.end()) {
            map[key] = add_to_right(head, key, 1);
        } else {
            auto node = map[key];
            node->keys.erase(key);
            if (node->right->val == node->val + 1) {
                node->right->keys.insert(key);
                map[key] = node->right;
            } else {
                map[key] = add_to_right(node, key, node->val + 1);
            }
            if (node->keys.empty()) {
                delete_node(node);
            }
        }
    }

    void dec(string key) {
        auto node = map[key];
        node->keys.erase(key);
        if (node->left->val == node->val - 1) {
            node->left->keys.insert(key);
            map[key] = node->left;
        } else {
            if (node->val != 1) {
                map[key] = add_to_right(node->left, key, node->val - 1);
            } else {
                map.erase(key);
            }
        }
        if (node->keys.empty()) {
            delete_node(node);
        }
    }

    string getMaxKey() {
        if (map.empty()) return "";
        return *tail->left->keys.begin();
    }

    string getMinKey() {
        if (map.empty()) return "";
        return *head->right->keys.begin();
    }
};