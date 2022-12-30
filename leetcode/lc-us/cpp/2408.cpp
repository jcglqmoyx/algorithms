#include <bits/stdc++.h>

using namespace std;

class SQL {
    struct Table {
        int rows = 0;
        map<int, vector<string>> records;
    };
    unordered_map<string, Table> tables;
public:
    SQL(vector<string> &names, vector<int> &columns) {
        for (auto &name: names) {
            Table t;
            tables[name] = t;
        }
    }

    void insertRow(string name, vector<string> row) {
        Table &t = tables[name];
        t.rows++;
        t.records[t.rows] = move(row);
    }

    void deleteRow(string name, int rowId) {
        tables[name].records.erase(rowId);
    }

    string selectCell(string name, int rowId, int columnId) {
        return tables[name].records[rowId][columnId - 1];
    }
};