#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s;
    cin >> s;
 
    vector<int> prefix;
    prefix.push_back(-1);
 
    for (int i = 1; i <= s.size(); i++) {
        int k = prefix[i - 1];
        while (k >= 0) {
            if (s[k] == s[i - 1]) {
                break;
            }
            k = prefix[k];
        }
 
        prefix.push_back(k + 1);
    }
 
    for (int i = 1; i <= s.size(); i++) {
        cout << prefix[i] << ' ';
    }
 
    return 0;
}