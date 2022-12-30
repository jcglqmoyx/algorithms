#include <bits/stdc++.h>

using namespace std;

class FileSystem {
public:
    FileSystem() {
        file_system = new Node();
        file_system->val = "/";
        file_system->is_directory = true;
    }

    vector<string> ls(string path) {
        auto v = get_path(path);

        auto node = this->file_system;
        for (int i = 1; i < v.size(); i++) {
            node = node->children[v[i]];
        }
        vector<string> res;
        if (node->is_directory) {
            for (const auto &it: node->children) {
                res.push_back(it.first);
            }
            sort(res.begin(), res.end());
        } else {
            res.push_back(node->val);
        }
        return res;
    }

    void mkdir(string path) {
        auto v = get_path(path);
        auto node = this->file_system;
        for (int i = 1; i < v.size(); i++) {
            if (!node->children.count(v[i])) {
                Node *child = new Node();
                child->val = v[i];
                child->is_directory = true;
                node->children[v[i]] = child;
            }
            node = node->children[v[i]];
        }
        node->is_directory = true;
    }

    void addContentToFile(string filePath, string content) {
        auto v = get_path(filePath);
        auto node = this->file_system;
        for (int i = 1; i < v.size(); i++) {
            if (!node->children.count(v[i])) {
                Node *child = new Node();
                child->val = v[i];
                node->children[v[i]] = child;
            }
            node = node->children[v[i]];
        }
        node->is_directory = false;
        node->content += content;
    }

    string readContentFromFile(string filePath) {
        auto v = get_path(filePath);
        auto node = this->file_system;
        for (int i = 1; i < v.size(); i++) {
            node = node->children[v[i]];
        }
        return node->content;
    }

private:
    static vector<string> get_path(string &path) {
        vector<string> v;
        v.emplace_back("/");
        int n = (int) path.size();
        for (int i = 1; i < n; i++) {
            int j = i + 1;
            while (j < n && path[j] != '/') j++;
            v.push_back(path.substr(i, j - i));
            i = j;
        }
        return v;
    }

    class Node {
    public:
        string val;
        string content;
        bool is_directory{};
        unordered_map<string, Node *> children;
    };

    Node *file_system;
};