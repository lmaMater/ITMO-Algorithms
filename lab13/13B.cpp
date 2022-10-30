#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string p, t;
    cin >> p >> t;
 
    string s = p + '#' + t;
 
    vector<int> prefix, ans;
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
        if (k + 1 == p.size()) {
            ans.push_back(i - 2 * (k + 1));
        }
    }
 
    cout << ans.size() << '\n';
    for (auto elem: ans) {
        cout << elem << ' ';
    }
 
    return 0;
}