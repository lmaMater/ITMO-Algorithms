#include <iostream>
#include <vector>
 
using namespace std;
 
typedef pair<pair<string, string>, int> triple;
 
const int size = 10000;
 
int hashFunc(string s) {
    int key = 12345;
    for (int i = 0; i < s.size(); i++) {
        key += (int(s[i]) * (i + 2));
    }
    return abs(key) % size;
}
 
struct MyLinkedMap {
    vector<vector<triple>> chains_array = vector<vector<triple>>(size, vector<triple>());
    vector<string> keys = vector<string>(100000, "");
    int key;
    int ind = 0;
 
    string get(string key_string) {
        key = hashFunc(key_string);
        for (auto p : chains_array[key]) {
            if (p.first.first == key_string) {
                return p.first.second;
            }
        }
        return "none";
    }
 
    int get_index(string key_string) {
        key = hashFunc(key_string);
        for (auto p : chains_array[key]) {
            if (p.first.first == key_string) {
                return p.second;
            }
        }
        return -1;
    }
 
    void put(string key_string, string value) {
        key = hashFunc(key_string);
        for (int i = 0; i < chains_array[key].size(); i++) {
            if (chains_array[key][i].first.first == key_string) {
                chains_array[key][i].first.second = value;
                return;
            }
        }
        chains_array[key].push_back(make_pair(make_pair(key_string, value), ind));
        keys[ind] = key_string;
        ind++;
    }
 
    void del(string key_string) {
        key = hashFunc(key_string);
        for (int i = 0; i < chains_array[key].size(); i++) {
            if (chains_array[key][i].first.first == key_string) {
                keys[chains_array[key][i].second] = "";
                chains_array[key].erase(chains_array[key].begin() + i);
                return;
            }
        }
    }
 
    string prev(string key_string) {
        int index = get_index(key_string) - 1;
        if (index >= 0) {
            for (; index >= 0; index--) {
                if (keys[index] != "") {
                    return get(keys[index]);
                }
            }
        }
        return "none";
    }
 
    string next(string key_string) {
        int index = get_index(key_string) + 1;
        if (index > 0) {
            for (; index < ind; index++) {
                if (keys[index] != "") {
                    return get(keys[index]);
                }
            }
        }
        return "none";
    }
};
 
int main() {
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    MyLinkedMap linked_map;
    string operation, key, value;
 
    while (cin >> operation) {
        cin >> key;
        if (operation == "put") {
            cin >> value;
            linked_map.put(key, value);
        }
        if (operation == "delete") {
            linked_map.del(key);
        }
        if (operation == "get") {
            cout << linked_map.get(key) << '\n';
        }
        if (operation == "prev") {
            cout << linked_map.prev(key) << '\n';
        }
        if (operation == "next") {
            cout << linked_map.next(key) << '\n';
        }
    }
 
    return 0;
}