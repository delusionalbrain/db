#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "hashTable.cpp"
using namespace std;

hashTable store;

string handle_command(const vector<string>& parts) {
    if (parts.empty()) return "-ERR empty command\r\n";

    string cmd = parts[0];
    transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);

    if (cmd == "JOKE") {
        return "+YOUARETHEJOKE\r\n";
    } 
    else if (cmd == "SET" && parts.size() >= 3) {
        store.set(parts[1], parts[2]);
        return "+OK\r\n";
    }
     else if (cmd == "GET" && parts.size() >= 2) {
        if (!store.exist(parts[1])) return "$-1\r\n";
        string val = store.get(parts[1]);
        return "$" + to_string(val.size()) + "\r\n" + val + "\r\n";
    }
     else if (cmd == "DEL" && parts.size() >= 2) {
        string result = store.dlt(parts[1]);
        return ":" + result + "\r\n";
    } 
    else if (cmd == "EXISTS" && parts.size() >= 2) {
        return store.exist(parts[1]) ? ":1\r\n" : ":0\r\n";
    }

    return "-ERR unknown command\r\n";
}