struct MyListNode {
    int key;
    MyListNode *next;

    MyListNode() : key(0), next(nullptr) {}

    MyListNode(int _key) : key(_key), next(nullptr) {}
};

class MyHashSet {
    const static int size = 997;
    MyListNode *bucket[size] = {};
public:
    MyHashSet() {
    }

    void add(int key) {
        int index = key % size;
        auto *head = bucket[index];
        if (!head) {
            bucket[index] = new MyListNode(key);
        } else {
            while (head) {
                if (head->key == key) {
                    break;
                }
                if (!head->next) {
                    head->next = new MyListNode(key);
                }
                head = head->next;
            }
        }
    }

    void remove(int key) {
        int index = key % size;
        MyListNode *head = bucket[index];
        if (!head) return;
        if (head->key == key) {
            if (!head->next) {
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
            }
            dummy = dummy->next;
        }
    }

    bool contains(int key) {
        int index = key % size;
        if (!bucket[index]) return false;
        MyListNode *head = bucket[index];
        while (head) {
            if (head->key == key) return true;
            head = head->next;
        }
        return false;
    }
};