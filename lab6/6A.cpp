#include <iostream>
#include <vector>
 
using namespace std;
 
int hashFunc(int x) {
    return ((abs(x + 31415926)) % 100000);
}
 
struct MySet{
    vector<vector<int>> chains_array = vector<vector<int>>(1e5, vector<int>());
    int key;
 
    bool exists (int x) {
        key = hashFunc(x);
        for (int el : chains_array[key]) {
            if (el == x) {
                return true;
            }
        }
        return false;
    }
 
    void insert (int x) {
        key = hashFunc(x);
        if (!exists(x)) {
            chains_array[key].push_back(x);
        }
    }
 
    void del (int x) {
        key = hashFunc(x);
        for (int i = 0; i < chains_array[key].size(); i++) {
            if (chains_array[key][i] == x) {
                chains_array[key].erase(chains_array[key].begin() + i);
                break;
            }
        }
    }
};
 
int main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    MySet my_set;
    string operation;
    int x;
 
    while (cin >> operation) {
        cin >> x;
        if (operation == "insert") {
            my_set.insert(x);
        }
        if (operation == "delete") {
            my_set.del(x);
        }
        if (operation == "exists") {
            if (my_set.exists(x)) {
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        }
    }
 
    return 0;
}