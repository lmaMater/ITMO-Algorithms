#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
size_t hashFunc(string s, size_t size) {
    size_t key = 123;
    for (size_t i = 0; i < s.size(); i += 2) {
        key += (size_t(s[i]) * (i + 2));
    }
    return size_t(abs(int(key)) % size);
}
 
struct MySet {
    vector<vector<string>> hash_table = vector<vector<string >>(1, vector<string>());
    vector<size_t> hashes;
    size_t key;
    size_t len = 0;
 
    bool exists(string x) {
        key = hashFunc(x, hash_table.size());
        for (string el: hash_table[key]) {
            if (el == x) {
                return true;
            }
        }
        return false;
    }
 
    void rehash() {
        vector<vector<string>> temp_table;
        vector<size_t> temp_hashes;
        temp_table.resize(2 * hash_table.size());
        for (auto hash: hashes) {
            for (auto el: hash_table[hash]) {
                key = hashFunc(el, temp_table.size());
                if (find(temp_hashes.begin(), temp_hashes.end(), key) == temp_hashes.end()) {
                    temp_hashes.push_back(key);
                }
                temp_table[key].push_back(el);
            }
        }
        hash_table = temp_table;
        hashes = temp_hashes;
    }
 
    bool insert(string x) {
        if (!exists(x)) {
            if (len + 1 > hash_table.size()) {
                rehash();
            }
            key = hashFunc(x, hash_table.size());
            hash_table[key].push_back(x);
            if (find(hashes.begin(), hashes.end(), key) == hashes.end()) {
                hashes.push_back(key);
            }
            len++;
            return true;
        }
        return false;
    }
 
    void del_set(string x) {
        key = hashFunc(x, hash_table.size());
        auto find_x = find(hash_table[key].begin(),
                           hash_table[key].end(), x);
        if (find_x != hash_table[key].end()) {
            hash_table[key].erase(find_x);
            len--;
        }
    }
 
    void print_set() {
        cout << len;
        if (len > 0) {
            for (auto h: hashes) {
                for (auto el: hash_table[h]) {
                    cout << " " << el;
                }
            }
        }
        cout << '\n';
    }
};
 
typedef pair<string, MySet> key_value;
 
struct MyMultiMap {
    vector<vector<key_value>> hash_table =
            vector<vector<key_value>>(480, vector<key_value>());
    vector<size_t> hashes;
    size_t key;
    size_t len = 0;
 
    void get(string key_string) {
        key = hashFunc(key_string, hash_table.size());
        for (auto p: hash_table[key]) {
            if (p.first == key_string) {
                p.second.print_set();
                return;
            }
        }
        cout << "0\n";
    }
 
    void rehash() {
        vector<vector<key_value>> temp_table;
        vector<size_t> temp_hashes;
        temp_table.resize(2 * hash_table.size());
        for (auto hash: hashes) {
            for (auto el: hash_table[hash]) {
                key = hashFunc(el.first, temp_table.size());
                if (find(temp_hashes.begin(), temp_hashes.end(), key) == temp_hashes.end()) {
                    temp_hashes.push_back(key);
                }
                temp_table[key].push_back(el);
            }
        }
        hash_table = temp_table;
        hashes = temp_hashes;
    }
 
    void put(string key_string, string value) {
        if (len + 1 > hash_table.size()) {
            rehash();
        }
        key = hashFunc(key_string, hash_table.size());
        for (size_t i = 0; i < hash_table[key].size(); i++) {
            if (hash_table[key][i].first == key_string) {
                if (hash_table[key][i].second.insert(value)) {
                    if (find(hashes.begin(), hashes.end(), key) == hashes.end()) {
                        hashes.push_back(key);
                    }
                    len++;
                }
                return;
            }
        }
        MySet new_set;
        new_set.insert(value);
        hash_table[key].push_back(make_pair(key_string, new_set));
        hashes.push_back(key);
        len++;
    }
 
    void del(string key_string, string value) {
        key = hashFunc(key_string, hash_table.size());
        for (size_t i = 0; i < hash_table[key].size(); i++) {
            if (hash_table[key][i].first == key_string) {
                hash_table[key][i].second.del_set(value);
                if (hash_table[key][i].second.len == 0) {
                    auto find_h = find(hashes.begin(),
                                       hashes.end(), key);
                    if (find_h != hashes.end()) {
                        hashes.erase(find_h);
                    }
                }
                break;
            }
        }
    }
 
    void deleteAll(string key_string) {
        key = hashFunc(key_string, hash_table.size());
        for (size_t i = 0; i < hash_table[key].size(); i++) {
            if (hash_table[key][i].first == key_string) {
                hash_table[key].erase(hash_table[key].begin() + i);
                auto find_h = find(hashes.begin(),
                                   hashes.end(), key);
                if (find_h != hashes.end()) {
                    hashes.erase(find_h);
                }
                len--;
                break;
            }
        }
    }
};
 
int main() {
//    freopen("sample.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    MyMultiMap multi_map;
    string operation, key, value;
 
    while (cin >> operation) {
        cin >> key;
        if (operation == "put") {
            cin >> value;
            multi_map.put(key, value);
        }
        if (operation == "delete") {
            cin >> value;
            multi_map.del(key, value);
        }
        if (operation == "deleteall") {
            multi_map.deleteAll(key);
        }
        if (operation == "get") {
            multi_map.get(key);
        }
    }
    return 0;
}