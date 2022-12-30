#include <bits/stdc++.h>

using namespace std;

class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        m_capacity = capacity;
    }

    void enqueue(int element) {
        unique_lock<mutex> lck(m_mtx);

        m_cv_not_full.wait(lck, [this] {
            return m_queue.size() < m_capacity;
        });

        m_queue.push(element);

        m_cv_not_empty.notify_one();
    }

    int dequeue() {
        unique_lock<mutex> lck(m_mtx);

        m_cv_not_empty.wait(lck, [this] {
            return !m_queue.empty();
        });

        int element = m_queue.front();
        m_queue.pop();

        m_cv_not_full.notify_one();

        return element;
    }

    int size() {
        unique_lock<mutex> lck(m_mtx);
        return m_queue.size();
    }

private:
    queue<int> m_queue;
    int m_capacity;
    mutex m_mtx;
    condition_variable m_cv_not_empty;
    condition_variable m_cv_not_full;
};