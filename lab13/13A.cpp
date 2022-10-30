#include <iostream>
#include <vector>
 
using namespace std;
 
string p, t;
 
bool checkIndex(int index) {
    int counter = 0;
    while (t[index] == p[counter] && counter < p.size()) {
        ++counter;
        ++index;
    }
 
    return counter == p.size();
}
 
int main() {
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> p >> t;
 
    vector<int> ans;
    for (int i = 0; i <= int(t.size()) - int(p.size()); i++) {
        if (checkIndex(i)) {
            ans.push_back(i + 1);
        }
    }
 
    cout << ans.size() << '\n';
    for (auto elem : ans) {
        cout << elem << ' ';
    }
 
    return 0;
}