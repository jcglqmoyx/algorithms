#include <bits/stdc++.h>

using namespace std;

class HtmlParser {
public:
    vector<string> getUrls(string url);
};

class Solution {
private:
    std::mutex mu;
    std::condition_variable cv_req, cv_res;
    int request_counter = 0;
    int exited_flag = 0;

    void func(HtmlParser &htmlParser, string &host_name, queue<string> &request_queue, queue<string> &result_queue) {
        while (true) {
            unique_lock<mutex> lk(mu);
            while (request_queue.empty() && exited_flag == 0) cv_req.wait(lk);
            if (exited_flag) return;
            string url = request_queue.front();
            request_queue.pop();
            lk.unlock();
            vector<string> urls = htmlParser.getUrls(url);
            for (const auto &e: urls) {
                int pos = (int) e.find('/', 7);
                string host = e.substr(7, pos - 7);
                if (host_name == host) {
                    lk.lock();
                    result_queue.push(e);
                    lk.unlock();
                }
            }
            lk.lock();
            this->request_counter--;
            lk.unlock();
            cv_res.notify_one();
        }
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        queue<string> request_queue;
        request_queue.push(startUrl);
        queue<string> result_queue;
        set<string> url_set;
        url_set.insert(startUrl);
        auto pos = startUrl.find('/', 7);
        string hostname = startUrl.substr(7, pos - 7);
        this->request_counter = 1;
        for (int i = 1; i <= 3; i++) {
            std::thread th(&Solution::func, this, std::ref(htmlParser), std::ref(hostname), ref(request_queue),
                           ref(result_queue));
            th.detach();
        }
        while (true) {
            unique_lock<mutex> lk(mu);
            while (result_queue.empty() && request_counter) {
                cv_res.wait(lk);
            }
            while (!result_queue.empty()) {
                string url = result_queue.front();
                result_queue.pop();
                if (url_set.find(url) != url_set.end()) continue;
                request_queue.push(url);
                url_set.insert(url);
                request_counter++;
            }
            cv_req.notify_all();
            if (request_counter == 0) {
                exited_flag = 1;
                break;
            }
        }
        vector<string> res;
        for (const auto &url: url_set) {
            res.push_back(url);
        }
        return res;
    }
};