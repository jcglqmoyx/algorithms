struct MyListNode {
    int key;
    int val;
    MyListNode *next;

    MyListNode() : val(0), next(nullptr) {}

    MyListNode(int _key, int _val) : key(_key), val(_val), next(nullptr) {}
};

class MyHashMap {
    static const int size = 997;
    MyListNode *bucket[size] = {nullptr};
public:
    MyHashMap() {
    }

    void put(int key, int value) {
        int index = key % size;
        if (bucket[index] == nullptr) {
            auto *node = new MyListNode(key, value);
            bucket[index] = node;
        } else {
            MyListNode *node = bucket[index];
            while (node) {
                if (node->key == key) {
                    node->val = value;
                    break;
                } else if (!node->next) {
                    node->next = new MyListNode(key, value);
                    break;
                }
                node = node->next;
            }
        }
    }

    int get(int key) {
        int index = key % size;
        MyListNode *head = bucket[index];
        while (head) {
            if (head->key == key) {
                return head->val;
            }
            head = head->next;
        }
        return -1;
    }

    void remove(int key) {
        int index = key % size;
        if (!bucket[index]) return;
        if (bucket[index]->key == key) {
            if (!bucket[index]->next) {
                bucket[index] = nullptr;
                return;
            } else {
                bucket[index] = bucket[index]->next;
            }
        }
        auto *dummy = new MyListNode();
        dummy->next = bucket[index];
        while (dummy && dummy->next) {
            if (dummy->next->key == key) {
                dummy->next = dummy->next->next;
                break;
            }
            dummy = dummy->next;
        }
    }
};