#include <iostream>
#include <vector>
 
using namespace std;
 
typedef pair<string, string> str_pair;
 
int hashFunc(string s) {
    int key = 12345;
    for (int i = 0; i < s.size(); i++) {
        key += (int(s[i]) * (i + 2));
    }
    return abs(key) % 10000;
}
 
struct MyMap {
    vector<vector<str_pair>> chains_array = vector<vector<str_pair>>(10000, vector<str_pair>());
    int key;
 
    string get(string key_string) {
        key = hashFunc(key_string);
        for (auto p : chains_array[key]) {
            if (p.first == key_string) {
                return p.second;
            }
        }
        return "none";
    }
 
    void put(string key_string, string value) {
        key = hashFunc(key_string);
        for (int i = 0; i < chains_array[key].size(); i++) {
            if (chains_array[key][i].first == key_string) {
                chains_array[key][i] = make_pair(key_string, value);
                return;
            }
        }
        chains_array[key].push_back(make_pair(key_string, value));
    }
 
    void del(string key_string) {
        key = hashFunc(key_string);
        for (int i = 0; i < chains_array[key].size(); i++) {
            if (chains_array[key][i].first == key_string) {
                chains_array[key].erase(chains_array[key].begin() + i);
                break;
            }
        }
    }
};
 
int main() {
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    MyMap my_map;
    string operation, key, value;
 
    while (cin >> operation) {
        cin >> key;
        if (operation == "put") {
            cin >> value;
            my_map.put(key, value);
        }
        if (operation == "delete") {
            my_map.del(key);
        }
        if (operation == "get") {
            cout << my_map.get(key) << '\n';
        }
    }
 
    return 0;
}